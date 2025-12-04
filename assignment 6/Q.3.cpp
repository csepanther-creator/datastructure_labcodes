#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

DNode* dnode_new(int v) {
    DNode *n = (DNode*)malloc(sizeof(DNode));
    if (!n) exit(1);
    n->data = v; n->prev = n->next = NULL;
    return n;
}

void dll_insert_end(DNode **head, int v) {
    DNode *n = dnode_new(v);
    if (*head == NULL) { *head = n; return; }
    DNode *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n; n->prev = cur;
}

int dll_size(DNode *head) {
    int c = 0;
    DNode *cur = head;
    while (cur) { c++; cur = cur->next; }
    return c;
}

void dll_display(DNode *head) {
    if (!head) { printf("[DLL empty]\n"); return; }
    DNode *cur = head;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" <-> ");
        cur = cur->next;
    }
    printf("\n");
}

void dll_free(DNode **head) {
    DNode *cur = *head;
    while (cur) { DNode *t = cur->next; free(cur); cur = t; }
    *head = NULL;
}

CNode* cnode_new(int v) {
    CNode *n = (CNode*)malloc(sizeof(CNode));
    if (!n) exit(1);
    n->data = v; n->next = NULL;
    return n;
}

void cll_insert_end(CNode **head, int v) {
    CNode *n = cnode_new(v);
    if (*head == NULL) { n->next = n; *head = n; return; }
    CNode *last = *head;
    while (last->next != *head) last = last->next;
    last->next = n; n->next = *head;
}

int cll_size(CNode *head) {
    if (head == NULL) return 0;
    int c = 0;
    CNode *cur = head;
    do { c++; cur = cur->next; } while (cur != head);
    return c;
}

void cll_display(CNode *head) {
    if (head == NULL) { printf("[CLL empty]\n"); return; }
    CNode *cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

void cll_free(CNode **head) {
    if (*head == NULL) return;
    CNode *cur = (*head)->next;
    while (cur != *head) { CNode *t = cur->next; free(cur); cur = t; }
    free(*head); *head = NULL;
}

void dll_menu() {
    DNode *head = NULL;
    while (1) {
        int c;
        printf("\nDLL Menu\n1.Insert end\n2.Display\n3.Size\n4.Back\nChoice: ");
        if (scanf("%d", &c) != 1) { while (getchar() != '\n'); continue; }
        if (c == 4) { dll_free(&head); break; }
        if (c == 1) {
            int v; printf("Value: "); if (scanf("%d",&v)!=1) { while(getchar()!='\n'); continue; }
            dll_insert_end(&head, v);
        } else if (c == 2) {
            dll_display(head);
        } else if (c == 3) {
            printf("Size = %d\n", dll_size(head));
        } else printf("Invalid\n");
    }
}

void cll_menu() {
    CNode *head = NULL;
    while (1) {
        int c;
        printf("\nCLL Menu\n1.Insert end\n2.Display\n3.Size\n4.Back\nChoice: ");
        if (scanf("%d", &c) != 1) { while (getchar() != '\n'); continue; }
        if (c == 4) { cll_free(&head); break; }
        if (c == 1) {
            int v; printf("Value: "); if (scanf("%d",&v)!=1) { while(getchar()!='\n'); continue; }
            cll_insert_end(&head, v);
        } else if (c == 2) {
            cll_display(head);
        } else if (c == 3) {
            printf("Size = %d\n", cll_size(head));
        } else printf("Invalid\n");
    }
}

int main(void) {
    while (1) {
        int ch;
        printf("\nQuestion 3: Size of DLL and CLL\n1.DLL\n2.CLL\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) { while (getchar() != '\n'); continue; }
        if (ch == 0) break;
        if (ch == 1) dll_menu();
        else if (ch == 2) cll_menu();
        else printf("Invalid\n");
    }
    return 0;
}

