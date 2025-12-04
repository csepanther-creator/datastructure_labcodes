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

DNode* dnode_new(int v){
    DNode *n = (DNode*)malloc(sizeof(DNode));
    if(!n) exit(1);
    n->data = v; n->prev = n->next = NULL; return n;
}

void dll_insert_begin(DNode **h, int v){
    DNode *n = dnode_new(v);
    if(*h == NULL){ *h = n; return; }
    n->next = *h; (*h)->prev = n; *h = n;
}

void dll_insert_end(DNode **h, int v){
    DNode *n = dnode_new(v);
    if(*h == NULL){ *h = n; return; }
    DNode *cur = *h;
    while(cur->next) cur = cur->next;
    cur->next = n; n->prev = cur;
}

int dll_insert_after(DNode **h, int key, int v){
    DNode *cur = *h;
    while(cur){
        if(cur->data == key){
            DNode *n = dnode_new(v);
            n->next = cur->next; n->prev = cur;
            if(cur->next) cur->next->prev = n;
            cur->next = n;
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

int dll_insert_before(DNode **h, int key, int v){
    if(*h == NULL) return 0;
    DNode *cur = *h;
    while(cur){
        if(cur->data == key){
            DNode *n = dnode_new(v);
            n->next = cur; n->prev = cur->prev;
            if(cur->prev) cur->prev->next = n;
            cur->prev = n;
            if(cur == *h) *h = n;
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

int dll_delete(DNode **h, int key){
    DNode *cur = *h;
    while(cur){
        if(cur->data == key){
            if(cur->prev) cur->prev->next = cur->next;
            else *h = cur->next;
            if(cur->next) cur->next->prev = cur->prev;
            free(cur);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

int dll_search(DNode *h, int key){
    int idx = 0;
    DNode *cur = h;
    while(cur){
        if(cur->data == key) return idx;
        cur = cur->next; idx++;
    }
    return -1;
}

void dll_display(DNode *h){
    if(!h){ printf("[DLL empty]\n"); return; }
    DNode *cur = h;
    while(cur){
        printf("%d", cur->data);
        if(cur->next) printf(" <-> ");
        cur = cur->next;
    }
    printf("\n");
}

void dll_free(DNode **h){
    DNode *cur = *h;
    while(cur){
        DNode *t = cur->next; free(cur); cur = t;
    }
    *h = NULL;
}

CNode* cnode_new(int v){
    CNode *n = (CNode*)malloc(sizeof(CNode));
    if(!n) exit(1);
    n->data = v; n->next = NULL; return n;
}

void cll_insert_begin(CNode **h, int v){
    CNode *n = cnode_new(v);
    if(*h == NULL){ n->next = n; *h = n; return; }
    CNode *last = *h;
    while(last->next != *h) last = last->next;
    n->next = *h; last->next = n; *h = n;
}

void cll_insert_end(CNode **h, int v){
    if(*h == NULL){ cll_insert_begin(h, v); return; }
    CNode *n = cnode_new(v);
    CNode *last = *h;
    while(last->next != *h) last = last->next;
    last->next = n; n->next = *h;
}

int cll_insert_after(CNode **h, int key, int v){
    if(*h == NULL) return 0;
    CNode *cur = *h;
    do{
        if(cur->data == key){
            CNode *n = cnode_new(v);
            n->next = cur->next; cur->next = n;
            return 1;
        }
        cur = cur->next;
    } while(cur != *h);
    return 0;
}

int cll_insert_before(CNode **h, int key, int v){
    if(*h == NULL) return 0;
    CNode *cur = *h;
    if(cur->data == key){ cll_insert_begin(h, v); return 1; }
    CNode *prev = cur; cur = cur->next;
    while(cur != *h){
        if(cur->data == key){
            CNode *n = cnode_new(v);
            prev->next = n; n->next = cur;
            return 1;
        }
        prev = cur; cur = cur->next;
    }
    return 0;
}

int cll_delete(CNode **h, int key){
    if(*h == NULL) return 0;
    CNode *cur = *h;
    if(cur->data == key){
        if(cur->next == cur){ free(cur); *h = NULL; return 1; }
        CNode *last = cur;
        while(last->next != *h) last = last->next;
        last->next = cur->next; *h = cur->next; free(cur); return 1;
    }
    CNode *prev = cur; cur = cur->next;
    while(cur != *h){
        if(cur->data == key){ prev->next = cur->next; free(cur); return 1; }
        prev = cur; cur = cur->next;
    }
    return 0;
}

int cll_search(CNode *h, int key){
    if(h == NULL) return -1;
    CNode *cur = h; int idx = 0;
    do{
        if(cur->data == key) return idx;
        cur = cur->next; idx++;
    } while(cur != h);
    return -1;
}

void cll_display(CNode *h){
    if(h == NULL){ printf("[CLL empty]\n"); return; }
    CNode *cur = h;
    do{
        printf("%d ", cur->data);
        cur = cur->next;
    } while(cur != h);
    printf("%d\n", h->data);
}

void cll_free(CNode **h){
    if(*h == NULL) return;
    CNode *cur = (*h)->next;
    while(cur != *h){ CNode *t = cur->next; free(cur); cur = t; }
    free(*h); *h = NULL;
}

void dll_menu(){
    DNode *head = NULL;
    for(;;){
        int c; printf("\nDLL Menu\n1.Insert at first\n2.Insert at last\n3.Insert after\n4.Insert before\n5.Delete node\n6.Search\n7.Display\n8.Back\nChoice: ");
        if(scanf("%d",&c)!=1){ while(getchar()!='\n'); continue; }
        if(c==8){ dll_free(&head); break; }
        int v,k;
        switch(c){
            case 1: printf("Value: "); scanf("%d",&v); dll_insert_begin(&head,v); break;
            case 2: printf("Value: "); scanf("%d",&v); dll_insert_end(&head,v); break;
            case 3: printf("Key: "); scanf("%d",&k); printf("Value: "); scanf("%d",&v); if(!dll_insert_after(&head,k,v)) printf("Key not found\n"); break;
            case 4: printf("Key: "); scanf("%d",&k); printf("Value: "); scanf("%d",&v); if(!dll_insert_before(&head,k,v)) printf("Key not found\n"); break;
            case 5: printf("Key to delete: "); scanf("%d",&k); if(dll_delete(&head,k)) printf("Deleted\n"); else printf("Not found\n"); break;
            case 6: printf("Key to search: "); scanf("%d",&k); { int idx = dll_search(head,k); if(idx>=0) printf("Found at %d\n",idx); else printf("Not found\n"); } break;
            case 7: dll_display(head); break;
            default: printf("Invalid\n");
        }
    }
}

void cll_menu(){
    CNode *head = NULL;
    for(;;){
        int c; printf("\nCLL Menu\n1.Insert at first\n2.Insert at last\n3.Insert after\n4.Insert before\n5.Delete node\n6.Search\n7.Display\n8.Back\nChoice: ");
        if(scanf("%d",&c)!=1){ while(getchar()!='\n'); continue; }
        if(c==8){ cll_free(&head); break; }
        int v,k;
        switch(c){
            case 1: printf("Value: "); scanf("%d",&v); cll_insert_begin(&head,v); break;
            case 2: printf("Value: "); scanf("%d",&v); cll_insert_end(&head,v); break;
            case 3: printf("Key: "); scanf("%d",&k); printf("Value: "); scanf("%d",&v); if(!cll_insert_after(&head,k,v)) printf("Key not found\n"); break;
            case 4: printf("Key: "); scanf("%d",&k); printf("Value: "); scanf("%d",&v); if(!cll_insert_before(&head,k,v)) printf("Key not found\n"); break;
            case 5: printf("Key to delete: "); scanf("%d",&k); if(cll_delete(&head,k)) printf("Deleted\n"); else printf("Not found\n"); break;
            case 6: printf("Key to search: "); scanf("%d",&k); { int idx = cll_search(head,k); if(idx>=0) printf("Found at %d\n",idx); else printf("Not found\n"); } break;
            case 7: cll_display(head); break;
            default: printf("Invalid\n");
        }
    }
}

int main(){
    for(;;){
        int c; printf("\nMain Menu\n1.Doubly Linked List\n2.Circular Linked List\n0.Exit\nChoice: ");
        if(scanf("%d",&c)!=1){ while(getchar()!='\n'); continue; }
        if(c==0) break;
        if(c==1) dll_menu();
        else if(c==2) cll_menu();
        else printf("Invalid\n");
    }
    return 0;
}

