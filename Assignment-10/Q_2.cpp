#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    unordered_set<int> a;
    for(int i=0;i<n;i++){ int x; cin>>x; a.insert(x); }
    set<int> common;
    for(int i=0;i<m;i++){ int x; cin>>x; if(a.count(x)) common.insert(x); }
    bool first=true;
    for(int v: common){
        if(!first) cout<<", ";
        cout<<v;
        first=false;
    }
    cout<<"\n";
    return 0;
}

