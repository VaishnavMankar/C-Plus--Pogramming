//1721.Swapping Nodes in a Linked List
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
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *first = head;
        ListNode *second = head;
        ListNode *current = head;

        int n = 0;

        // First pass: find length and the kth node from start
        while (current) {
            if (n == k - 1)
                first = current;
            current = current->next;
            n++;
        }

        // Second pass: find the kth node from the end
        current = head;
        for (int i = 0; i < n - k; i++) {
            second = second->next;
        }

        // Swap values
        swap(first->val, second->val);

        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test node swapping
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Position to swap

    cout << "Original linked list: ";
    printList(head);

    Solution sol;
    head = sol.swapNodes(head, k);

    cout << "Linked list after swapping nodes: ";
    printList(head);

    return 0;
}
