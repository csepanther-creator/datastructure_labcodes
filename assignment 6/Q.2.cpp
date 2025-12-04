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

void insert_end(Node **head, int v) {
    Node *n = new_node(v);
    if (*head == NULL) { n->next = n; *head = n; return; }
    Node *cur = *head;
    while (cur->next != *head) cur = cur->next;
    cur->next = n;
    n->next = *head;
}

void display_repeat_head(Node *head) {
    if (head == NULL) { printf("[CLL empty]\n"); return; }
    Node *cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("%d\n", head->data);
}

void free_cll(Node **head) {
    if (*head == NULL) return;
    Node *cur = (*head)->next;
    while (cur != *head) {
        Node *t = cur->next;
        free(cur);
        cur = t;
    }
    free(*head);
    *head = NULL;
}

int main(void) {
    Node *head = NULL;
    int n;
    printf("How many nodes to insert? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("No nodes inserted.\n");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int v;
        printf("Enter value %d: ", i+1);
        if (scanf("%d", &v) != 1) { printf("Invalid input\n"); free_cll(&head); return 0; }
        insert_end(&head, v);
    }
    printf("CLL with head repeated at end:\n");
    display_repeat_head(head);
    free_cll(&head);
    return 0;
}

