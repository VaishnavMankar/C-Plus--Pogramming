//21. Merge to Sorted List
//Class OP

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        // If one list is empty, return the other
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *nh = nullptr;  // New head of merged list

        // Start merging based on the lowest value node
        if (list1->val < list2->val) {
            nh = list1;
            list1 = list1->next;
        } else {
            nh = list2;
            list2 = list2->next;
        }

        ListNode *curr = nh;  // Pointer to track the last node in the merged list

        // Merge the lists iteratively
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // Append remaining nodes from non-empty list
        if (!list1) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }

        return nh;  // Return the head of the merged list
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example test cases
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    ListNode* list1 = createLinkedList(arr1, 3);
    ListNode* list2 = createLinkedList(arr2, 3);

    cout << "List 1: ";
    printLinkedList(list1);

    cout << "List 2: ";
    printLinkedList(list2);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printLinkedList(mergedList);

    return 0;
}
