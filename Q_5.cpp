#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct Node { int v; Node* next; Node(int x):v(x),next(nullptr){} };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<Node*> nodes;
    for(int i=0;i<n;i++){ int x; cin>>x; nodes.push_back(new Node(x)); if(i>0) nodes[i-1]->next = nodes[i]; }
    int pos; cin>>pos;
    if(pos>=0 && pos<n && n>0) nodes.back()->next = nodes[pos];
    unordered_set<Node*> seen;
    Node* cur = n?nodes[0]:nullptr;
    bool cycle=false;
    while(cur){
        if(seen.count(cur)){ cycle=true; break; }
        seen.insert(cur);
        cur = cur->next;
    }
    cout<<(cycle?"true":"false")<<"\n";
    return 0;
}

