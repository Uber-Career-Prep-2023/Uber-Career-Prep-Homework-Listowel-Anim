#include <iostream>

struct Node {
    int val;
    Node *next;
};

//Time Complexity: O(1)
Node* insertAtFront(Node *head, int val) {
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = head;
    return newNode;
}

//Time Complexity: O(n)
void insertAtBack(Node *head, int val) {
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    while (head->next != nullptr) {
        head = head->next;
    }
    head->next = newNode;
}

// Time Complexity: O(1)
void insertAfter(Node *head, int val, Node *loc) {
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = loc->next;
    loc->next = newNode;
}

//Time Complexity: O(1)
Node* deleteFront(Node *head) {
    Node *newHead = head->next;
    delete head;
    return newHead;
}

//Time COmplexity: O(n)
void deleteBack(Node *head) {
    while (head->next->next != nullptr) {
        head = head->next;
    }
    delete head->next;
    head->next = nullptr;
}

//Time Complexity: O(n)
Node* deleteNode(Node *head, Node *loc) {
    if (head == loc) {
        return deleteFront(head);
    }
    Node *prev = head;
    while (prev->next != loc) {
        prev = prev->next;
    }
    prev->next = loc->next;
    delete loc;
    return head;
}

//Time Complexity: O(n)
int length(Node *head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

//TIme Complexity: O(n)
Node* reverseIterative(Node *head) {
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//Time Complexity: O(n)
Node* reverseRecursiveHelper(Node *prev, Node *curr) {
    if (curr == nullptr) {
        return prev;
    }
    Node *next = curr->next;
    curr->next = prev;
    return reverseRecursiveHelper(curr, next);
}

Node* reverseRecursive(Node *head) {
    return reverseRecursiveHelper(nullptr, head);
}

int main() {
    Node *head = new Node;
    head->val = 1;
    head->next = nullptr;

    head = insertAtFront(head, 0);
    insertAtBack(head, 2);

    Node *loc = head->next;
    insertAfter(head, -1, loc);

    head = deleteFront(head);
    deleteBack(head);
    loc = head->next->next;
    head = deleteNode(head, loc);

    std::cout << "Length: " << length(head) << std::endl;

    head = reverseIterative(head);
    head = reverseRecursive(head);

    return 0;
}
