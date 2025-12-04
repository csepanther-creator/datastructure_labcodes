#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int,int> cnt;
    for(int x: a) cnt[x]++;
    int ans = -1;
    for(int x: a) if(cnt[x]==1){ ans = x; break; }
    cout<<ans<<"\n";
    return 0;
}

