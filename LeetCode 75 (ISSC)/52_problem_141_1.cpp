//141. Linked List Cycle
//Class OP

#include <iostream>
#include <unordered_set>
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
    bool hasCycle(ListNode *head) {
        ListNode *t = head;
        ListNode *h = head;
        while (h && h->next) {
            t = t->next;
            h = h->next->next;
            if (t == h) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Creating a sample linked list: 3 -> 2 -> 0 -> -4, with a cycle back to the 2nd node
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creating a cycle

    Solution sol;
    bool result = sol.hasCycle(head);

    cout << "Does the linked list have a cycle? " << (result ? "Yes" : "No") << endl;

    // No memory deallocation since the list contains a cycle

    return 0;
}
