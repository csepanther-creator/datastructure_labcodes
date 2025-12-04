#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void push(int data) {
    Node* newNode = new Node{data, head};
    head = newNode;
}

void reverseList() {
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void printList() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    push(4); push(3); push(2); push(1);

    cout << "Original List: ";
    printList();

    reverseList();

    cout << "Reversed List: ";
    printList();
}

