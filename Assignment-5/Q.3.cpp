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

void findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle Node: " << slow->data << endl;
}

int main() {
    push(5); push(4); push(3); push(2); push(1);
    cout << "List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL\n";
    findMiddle(head);
}

