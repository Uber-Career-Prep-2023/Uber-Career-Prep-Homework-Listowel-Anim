//Time Complexity: O(n)
//Space Complexity: O(1)
//Time Spent on Problem: 12 minutes
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            return;
        }
        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new ListNode(val);
    }

    void print() {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void removeDuplicates() {
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
    }
};

int main() {
    LinkedList list1;
    list1.insert(1);
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(3);
    list1.insert(3);
    cout << "Original list: ";
    list1.print();
    list1.removeDuplicates();
    cout << "List with duplicates removed: ";
    list1.print();

    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    cout << "Original list: ";
    list2.print();
    list2.removeDuplicates();
    cout << "List with duplicates removed: ";
    list2.print();

    return 0;
}
