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

int deleteOccurrences(int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == key) {
            count++;
            if (temp == head) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return count;
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
    push(1); push(3); push(1); push(2); push(1); push(2); push(1);

    cout << "Original List: ";
    printList();

    int key = 1;
    int count = deleteOccurrences(key);
    cout << "Count of " << key << ": " << count << endl;

    cout << "Updated List: ";
    printList();
}

