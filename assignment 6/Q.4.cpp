#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* new_node(char c) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) exit(1);
    n->data = c;
    n->prev = n->next = NULL;
    return n;
}

void insert_end(Node **head, char c) {
    Node *n = new_node(c);
    if (*head == NULL) { *head = n; return; }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    n->prev = cur;
}

Node* build_from_string(const char *s) {
    Node *head = NULL;
    for (size_t i = 0; i < strlen(s); ++i) {
        if (isalnum((unsigned char)s[i])) insert_end(&head, (char)tolower((unsigned char)s[i]));
    }
    return head;
}

int is_palindrome(Node *head) {
    if (!head) return 1;
    Node *l = head;
    Node *r = head;
    while (r->next) r = r->next;
    while (l != r && l->prev != r) {
        if (l->data != r->data) return 0;
        l = l->next;
        r = r->prev;
    }
    return 1;
}

void free_list(Node **head) {
    Node *cur = *head;
    while (cur) {
        Node *t = cur->next;
        free(cur);
        cur = t;
    }
    *head = NULL;
}

int main(void) {
    char buf[1024];
    while (1) {
        printf("Enter string (empty line to exit):\n");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        size_t L = strlen(buf);
        if (L && buf[L-1] == '\n') buf[L-1] = '\0';
        if (strlen(buf) == 0) break;
        Node *head = build_from_string(buf);
        int ans = is_palindrome(head);
        printf("%s\n", ans ? "Palindrome" : "Not palindrome");
        free_list(&head);
    }
    return 0;
}

