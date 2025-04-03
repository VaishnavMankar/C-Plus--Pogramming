//876. Middle of the Link List
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
    ListNode *middleNode(ListNode *head) {
        ListNode *t = head;
        ListNode *h = head;
        while (h->next && h->next->next) {
            t = t->next;
            h = h->next->next;
        }
        return (!h->next) ? t : t->next;
    }
};

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *middle = sol.middleNode(head);

    cout << "Middle of the linked list: " << middle->val << endl;

    // Free allocated memory
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
