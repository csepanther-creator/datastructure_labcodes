#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
};

Node* head = nullptr;

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

void insertSpecific(int data, int key, bool after) {
    Node* newNode = createNode(data);
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node " << key << " not found!\n";
        delete newNode;
        return;
    }

    if (after) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        if (temp == head) {
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteSpecific(int key) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node " << key << " not found!\n";
        return;
    }

    if (temp == head)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << "\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
}


