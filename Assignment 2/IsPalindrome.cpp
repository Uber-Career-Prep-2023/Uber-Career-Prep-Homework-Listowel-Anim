//Time Complexity: O(n)
//Space Complexity: O(n)
//Time Spent: 17 minutes
//Two Pointer Technique Employed: Doubly linked list forward-backward two-pointer
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    bool isPalindrome() {
        if (head == nullptr) {
            return true;
        }
        Node* currentForward = head;
        Node* currentBackward = tail;
        while (currentForward != currentBackward && currentBackward->next != currentForward) {
            if (currentForward->data != currentBackward->data) {
                return false;
            }
            currentForward = currentForward->next;
            currentBackward = currentBackward->prev;
        }
        return true;
    }

    void insert(int val) {
        Node* node = new Node(val);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverseList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
        Node* temp = head;
        head = tail;
        tail = temp;
    }
};

int main() {
    DoublyLinkedList dll1;
    dll1.insert(1);
    dll1.insert(2);
    dll1.insert(3);
    dll1.insert(2);
    dll1.insert(1);
    dll1.printList();
    dll1.reverseList();
    dll1.printList();
    cout << "Is dll1 a palindrome? " << dll1.isPalindrome() << endl;

    DoublyLinkedList dll2;
    dll2.insert(1);
    dll2.insert(2);
    dll2.insert(3);
    dll2.insert(4);
    dll2.insert(5);
    dll2.printList();
    dll2.reverseList();
    dll2.printList();
    cout << "Is dll2 a palindrome? " << dll2.isPalindrome() << endl;

    return 0;
}

