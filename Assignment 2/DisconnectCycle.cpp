//Time complexity: O(n)
//Space complexity: O(1)
//Time Spent: 17 minutes
//Two Pointer Technique Used: Linked List Fast Slow Two Pointer


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void disconnectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find the meeting point of the two pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        // If there is a cycle, disconnect it
        if (fast != nullptr && fast->next != nullptr) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = nullptr;
        }
    }
};

int main() {
    // Test case 1: No cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    Solution sol1;
    sol1.disconnectCycle(head1);
    ListNode* current1 = head1;
    while (current1 != nullptr) {
        cout << current1->val << " ";
        current1 = current1->next;
    } // Output: 1 2 3 4 5

    // Test case 2: Cycle exists
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = head2->next;
    Solution sol2;
    sol2.disconnectCycle(head2);
    ListNode* current2 = head2;
    while (current2 != nullptr) {
        cout << current2->val << " ";
        current2 = current2->next;
    } // Output: 1 2 3 4 5

    // Test case 3: Cycle exists at the head
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);
    head3->next->next->next->next = new ListNode(5);
    head3->next->next->next->next->next = head3;
    Solution sol3;
    sol3.disconnectCycle(head3);
    ListNode* current3 = head3;
    while (current3 != nullptr) {
        cout << current3->val << " ";
        current3 = current3->next;
    } // Output: 1 2 3 4 5
    return 0;
}
