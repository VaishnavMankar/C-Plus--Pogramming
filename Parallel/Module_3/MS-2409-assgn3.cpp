#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to swap two numbers
void swap(int* arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

// Recursive QuickSort
void quicksort(int* arr, int start, int end) {
    if (end <= 1)
        return;

    int pivot = arr[start + end / 2];
    swap(arr, start, start + end / 2);

    int index = start;
    for (int i = start + 1; i < start + end; i++) {
        if (arr[i] < pivot) {
            index++;
            swap(arr, i, index);
        }
    }

    swap(arr, start, index);

    quicksort(arr, start, index - start);
    quicksort(arr, index + 1, start + end - index - 1);
}

// Merge two sorted arrays
int* merge(int* arr1, int n1, int* arr2, int n2) {
    int* result = (int*)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k;

    for (k = 0; k < n1 + n2; k++) {
        if (i >= n1) result[k] = arr2[j++];
        else if (j >= n2) result[k] = arr1[i++];
        else if (arr1[i] < arr2[j]) result[k] = arr1[i++];
        else result[k] = arr2[j++];
    }
    return result;
}

// Driver Code
int main(int argc, char* argv[]) {
    int number_of_elements;
    int* data = NULL;
    int chunk_size, own_chunk_size;
    int* chunk;
    FILE* file = NULL;
    double time_taken = 0.0;
    MPI_Status status;

    // Check arguments
    if (argc < 2) {
        printf("Usage: mpirun -np <num_procs> ./program <input.txt> [output.txt]\n");
        exit(-1);
    }

    // Set default output file if not provided
    const char* input_file = argv[1];
    const char* output_file = (argc >= 3) ? argv[2] : "output.txt";

    int number_of_process, rank_of_process;
    int rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error initializing MPI. Terminating.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }

    MPI_Comm_size(MPI_COMM_WORLD, &number_of_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank_of_process);

    if (rank_of_process == 0) {
        // Read input file
        file = fopen(input_file, "r");
        if (file == NULL) {
            printf("Error opening input file: %s\n", input_file);
            MPI_Abort(MPI_COMM_WORLD, -1);
        }

        printf("Reading number of elements from file...\n");
        fscanf(file, "%d", &number_of_elements);
        printf("Number of elements: %d\n", number_of_elements);

        // Calculate chunk size
        chunk_size = (number_of_elements + number_of_process - 1) / number_of_process;

        data = (int*)malloc(number_of_process * chunk_size * sizeof(int));

        printf("Reading elements from file...\n");
        for (int i = 0; i < number_of_elements; i++)
            fscanf(file, "%d", &data[i]);

        // Padding remaining space
        for (int i = number_of_elements; i < number_of_process * chunk_size; i++)
            data[i] = 0;

        fclose(file);

        printf("Input array:\n");
        for (int i = 0; i < number_of_elements; i++)
            printf("%d ", data[i]);
        printf("\n");
    }

    MPI_Barrier(MPI_COMM_WORLD);
    time_taken -= MPI_Wtime();

    // Broadcast number of elements
    MPI_Bcast(&number_of_elements, 1, MPI_INT, 0, MPI_COMM_WORLD);

    chunk_size = (number_of_elements + number_of_process - 1) / number_of_process;
    chunk = (int*)malloc(chunk_size * sizeof(int));

    MPI_Scatter(data, chunk_size, MPI_INT, chunk, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
    if (data) { free(data); data = NULL; }

    own_chunk_size = (number_of_elements >= chunk_size * (rank_of_process + 1))
                         ? chunk_size
                         : (number_of_elements - chunk_size * rank_of_process);

    quicksort(chunk, 0, own_chunk_size);

    for (int step = 1; step < number_of_process; step *= 2) {
        if (rank_of_process % (2 * step) != 0) {
            MPI_Send(chunk, own_chunk_size, MPI_INT, rank_of_process - step, 0, MPI_COMM_WORLD);
            break;
        }
        if (rank_of_process + step < number_of_process) {
            int recv_size = (number_of_elements >= chunk_size * (rank_of_process + 2 * step))
                                ? (chunk_size * step)
                                : (number_of_elements - chunk_size * (rank_of_process + step));

            int* recv_chunk = (int*)malloc(recv_size * sizeof(int));
            MPI_Recv(recv_chunk, recv_size, MPI_INT, rank_of_process + step, 0, MPI_COMM_WORLD, &status);

            data = merge(chunk, own_chunk_size, recv_chunk, recv_size);
            free(chunk);
            free(recv_chunk);
            chunk = data;
            own_chunk_size += recv_size;
        }
    }

    time_taken += MPI_Wtime();

    if (rank_of_process == 0) {
        file = fopen(output_file, "w");
        if (file == NULL) {
            printf("Error opening output file: %s\n", output_file);
            exit(-1);
        }

        fprintf(file, "Total number of elements: %d\n", own_chunk_size);
        for (int i = 0; i < own_chunk_size; i++)
            fprintf(file, "%d ", chunk[i]);
        fclose(file);

        printf("\nResults written to %s\n", output_file);
        printf("Sorted array:\n");
        for (int i = 0; i < own_chunk_size; i++)
            printf("%d ", chunk[i]);
        printf("\n\nQuicksort %d ints on %d procs: %f secs\n",
               number_of_elements, number_of_process, time_taken);
    }

    MPI_Finalize();
    return 0;
}
