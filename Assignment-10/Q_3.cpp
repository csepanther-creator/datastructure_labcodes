#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    unordered_map<int,int> freq;
    vector<int> order;
    for(int x: arr){
        if(!freq.count(x)) order.push_back(x);
        freq[x]++;
    }
    for(int v: order){
        cout<<v<<" -> "<<freq[v];
        if(freq[v]==1) cout<<" time\n"; else cout<<" times\n";
    }
    return 0;
}

