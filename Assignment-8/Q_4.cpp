#include <iostream>
#include <limits>
using namespace std;

struct Node { long long v; Node* l; Node* r; Node(long long x): v(x), l(nullptr), r(nullptr) {} };

Node* build_preorder(){
    long long x;
    if(!(cin>>x)) return nullptr;
    if(x == -1) return nullptr;
    Node* n = new Node(x);
    n->l = build_preorder();
    n->r = build_preorder();
    return n;
}

bool is_bst(Node* node, long long low, long long high){
    if(!node) return true;
    if(node->v <= low || node->v >= high) return false;
    return is_bst(node->l, low, node->v) && is_bst(node->r, node->v, high);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = build_preorder();
    bool ok = is_bst(root, LLONG_MIN, LLONG_MAX);
    cout << (ok ? "BST\n" : "Not BST\n");
    return 0;
}

