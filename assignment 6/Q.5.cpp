#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) exit(1);
    n->data = v;
    n->next = NULL;
    return n;
}

int is_circular(Node *head) {
    if (!head) return 0;
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main(void) {
    int n;
    printf("How many nodes to create? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("No nodes created.\n");
        return 0;
    }
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i) {
        int v;
        printf("Enter value %d: ", i+1);
        if (scanf("%d", &v) != 1) { printf("Invalid input\n"); return 0; }
        Node *nn = new_node(v);
        if (!head) head = tail = nn;
        else { tail->next = nn; tail = nn; }
    }
    printf("Enter index to link tail to (1..%d) or 0 for none: ", n);
    int idx;
    if (scanf("%d", &idx) != 1) { printf("Invalid input\n"); return 0; }
    if (idx > 0 && idx <= n) {
        Node *cur = head;
        for (int i = 1; i < idx; ++i) cur = cur->next;
        tail->next = cur;
    }
    int cyc = is_circular(head);
    printf("Cycle detected? %s\n", cyc ? "Yes" : "No");
    if (!cyc) {
        Node *cur = head;
        while (cur) {
            Node *t = cur->next;
            free(cur);
            cur = t;
        }
    } else {
        printf("List contains a cycle; nodes not freed to avoid unsafe traversal.\n");
    }
    return 0;
}

