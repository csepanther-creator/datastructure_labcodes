#include <iostream>
#include <unordered_set>
using namespace std;
struct Node { int v; Node* l; Node* r; Node(int x):v(x),l(nullptr),r(nullptr){} };
Node* build(){
    int x;
    if(!(cin>>x)) return nullptr;
    if(x==-1) return nullptr;
    Node* n = new Node(x);
    n->l = build();
    n->r = build();
    return n;
}
bool findDuplicate(Node* root, unordered_set<int>& s){
    if(!root) return false;
    if(s.count(root->v)) return true;
    s.insert(root->v);
    return findDuplicate(root->l, s) || findDuplicate(root->r, s);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = build();
    unordered_set<int> s;
    bool dup = findDuplicate(root, s);
    cout<<(dup ? "Duplicates Found" : "No Duplicates")<<"\n";
    return 0;
}

