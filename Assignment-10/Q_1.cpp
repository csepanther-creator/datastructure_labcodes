#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    unordered_set<int> s;
    bool found=false;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(s.count(x)) found=true;
        s.insert(x);
    }
    cout<<(found?"true":"false")<<"\n";
    return 0;
}

