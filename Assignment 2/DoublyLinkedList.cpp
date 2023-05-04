
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Time Complexity: O(1)
Node* insertAtFront(Node* head, int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

// Time Complexity: O(n)
void insertAtBack(Node* head, int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
    newNode->prev = head;
}

// Time Complexity: O(1)
void insertAfter(Node* head, int val, Node* loc) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->prev = loc;
    newNode->next = loc->next;
    if (loc->next != NULL) {
        loc->next->prev = newNode;
    }
    loc->next = newNode;
}

// Time Complexity: O(1)
Node* deleteFront(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head->next;
    delete head;
    if (temp != NULL) {
        temp->prev = NULL;
    }
    return temp;
}

// Time Complexity: O(n)
void deleteBack(Node* head) {
    if (head == NULL) {
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    if (head->prev != NULL) {
        head->prev->next = NULL;
    }
    delete head;
}

// Time Complexity: O(n)
Node* deleteNode(Node* head, Node* loc) {
    if (head == NULL || loc == NULL) {
        return head;
    }
    if (head == loc) {
        head = head->next;
    }
    if (loc->prev != NULL) {
        loc->prev->next = loc->next;
    }
    if (loc->next != NULL) {
        loc->next->prev = loc->prev;
    }
    delete loc;
    return head;
}

// Time Complexity: O(n)
int length(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Time Complexity: O(n)
Node* reverseIterative(Node* head) {
    Node* prevNode = NULL;
    Node* currentNode = head;
    Node* nextNode = NULL;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        currentNode->prev = nextNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}

// Time Complexity: O(n)
Node* reverseRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    return newHead;
}
int main() {
    Node* head = NULL;
    head = insertAtFront(head, 5);
    insertAtBack(head, 10);
    Node* loc = head->next;
    insertAfter(head, 15, loc);
    cout << "Length of list: " << length(head) << endl;
    head = deleteFront(head);
    deleteBack(head);
    head = deleteNode(head, loc);
    cout << "Length of list: " << length(head) << endl;
    head = reverseIterative(head);
    head = reverseRecursive(head);
    return 0;
}
