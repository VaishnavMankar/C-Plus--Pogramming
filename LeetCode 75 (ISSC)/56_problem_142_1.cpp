// 142. Linked List Cycle ll
// Class OP

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *s = head, *f = head;

        // Using Floyd's Cycle Detection Algorithm to find cycle
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) 
                break;
        }

        // If no cycle exists, return null
        if (f == NULL || f->next == NULL)
            return NULL;

        // Finding the start of the cycle
        s = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }

        return s; // Returns the node where the cycle begins
    }
};

// Main function to test cycle detection
int main() {
    // Creating a sample linked list with a cycle: 3 -> 2 -> 0 -> -4 -> (back to 2)
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creates a cycle

    Solution sol;
    ListNode *cycleStart = sol.detectCycle(head);

    if (cycleStart)
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
