#include <iostream>
//TIme Complexity: O(n)
//Space Complexity: O(1)
//Time Spent: 19 minutes
//Two Pointer Technique Used: Linked list fast-slow two-pointer

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* moveNthFromEndToFront(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        for (int i = 0; i < n; i++) {
            if (q == nullptr) {
                return head;
            }
            q = q->next;
        }
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        ListNode* node = p->next;
        p->next = node->next;
        node->next = dummy->next;
        dummy->next = node;
        return dummy->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    printList(head1); // 1 2 3 4 5
    ListNode* newHead1 = sol.moveNthFromEndToFront(head1, 2);
    printList(newHead1); // 4 1 2 3 5

    ListNode* head2 = new ListNode(1);
    printList(head2); // 1
    ListNode* newHead2 = sol.moveNthFromEndToFront(head2, 1);
    printList(newHead2); // 1

    ListNode* head3 = nullptr;
    ListNode* newHead3 = sol.moveNthFromEndToFront(head3, 1);
    printList(newHead3); // nullptr

    return 0;
}
