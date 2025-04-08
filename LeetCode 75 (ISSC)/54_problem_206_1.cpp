//206. Reverse Linked List
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
    // Function to reverse a singly linked list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;  // Previous node pointer (initially null)
        ListNode *tmp = nullptr;   // Temporary pointer to hold next node
        ListNode *curr = head;     // Pointer to current node

        // Iterate through the list and reverse links
        while (curr != nullptr) {
            tmp = curr->next;  // Store next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move previous pointer forward
            curr = tmp;        // Move current pointer forward
        }

        return prev;  // New head of the reversed list
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
    // Example test case: Original linked list
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr, 5);

    cout << "Original List: ";
    printLinkedList(head);

    // Reverse the linked list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    cout << "Reversed List: ";
    printLinkedList(reversedHead);

    return 0;
}
