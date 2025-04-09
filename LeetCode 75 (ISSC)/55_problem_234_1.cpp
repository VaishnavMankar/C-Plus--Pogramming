//234. Palindrome Linked List
// Class OP

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
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true; // Edge case: empty list or single node
        
        // Finding the middle of the linked list
        ListNode *t = head;
        ListNode *h = head;
        while (h->next && h->next->next) {
            t = t->next;
            h = h->next->next;
        }

        // Reversing the second half of the linked list
        ListNode *prev = nullptr;
        ListNode *tmp = nullptr;
        ListNode *curr = t->next;
        while (curr != nullptr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // Comparing both halves
        ListNode *p1 = head;
        ListNode *p2 = prev;
        while (p2) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};

// Main function to test the palindrome linked list check
int main() {
    // Creating a sample linked list: 1 -> 2 -> 2 -> 1 (Palindrome)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;
    if (sol.isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}
