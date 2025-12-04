#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right, *parent;
    Node(int k): key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* bst_insert(Node* root, int k) {
    if (!root) return new Node(k);
    Node* cur = root;
    Node* par = nullptr;
    while (cur) {
        par = cur;
        if (k < cur->key) cur = cur->left;
        else if (k > cur->key) cur = cur->right;
        else return root;
    }
    Node* n = new Node(k);
    n->parent = par;
    if (k < par->key) par->left = n; else par->right = n;
    return root;
}

Node* bst_search_rec(Node* root, int k) {
    if (!root) return nullptr;
    if (root->key == k) return root;
    if (k < root->key) return bst_search_rec(root->left, k);
    return bst_search_rec(root->right, k);
}

Node* bst_search_iter(Node* root, int k) {
    Node* cur = root;
    while (cur) {
        if (cur->key == k) return cur;
        if (k < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

Node* bst_min(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* bst_max(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

Node* inorder_successor(Node* x) {
    if (!x) return nullptr;
    if (x->right) return bst_min(x->right);
    Node* p = x->parent;
    while (p && x == p->right) { x = p; p = p->parent; }
    return p;
}

Node* inorder_predecessor(Node* x) {
    if (!x) return nullptr;
    if (x->left) {
        Node* t = x->left;
        while (t->right) t = t->right;
        return t;
    }
    Node* p = x->parent;
    while (p && x == p->left) { x = p; p = p->parent; }
    return p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    Node* root = nullptr;
    for(int i=0;i<n;i++){ int v; cin>>v; if(!root) root = new Node(v); else root = bst_insert(root, v); }
    int k; cin>>k;
    cout << (bst_search_rec(root,k) ? "Found\n" : "Not Found\n");
    cout << (bst_search_iter(root,k) ? "Found\n" : "Not Found\n");
    Node* mn = bst_min(root);
    Node* mx = bst_max(root);
    cout << (mn ? mn->key : -1) << "\n";
    cout << (mx ? mx->key : -1) << "\n";
    Node* node = bst_search_iter(root,k);
    Node* succ = inorder_successor(node);
    Node* pred = inorder_predecessor(node);
    cout << (succ ? succ->key : -1) << "\n";
    cout << (pred ? pred->key : -1) << "\n";
    return 0;
}

