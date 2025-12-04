#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mode; if(!(cin>>mode)) return 0;
    int n; cin>>n;
    if(mode==1){
        priority_queue<long long> pq;
        for(int i=0;i<n;i++){ long long x; cin>>x; pq.push(x); }
        int q; cin>>q;
        while(q--){
            int cmd; cin>>cmd;
            if(cmd==0) break;
            if(cmd==1){ long long x; cin>>x; pq.push(x); }
            else if(cmd==2){
                if(pq.empty()) cout<<"Empty\n"; else { cout<<pq.top()<<"\n"; pq.pop(); }
            } else if(cmd==3){
                if(pq.empty()) cout<<"Empty\n"; else cout<<pq.top()<<"\n";
            }
        }
    } else {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=0;i<n;i++){ long long x; cin>>x; pq.push(x); }
        int q; cin>>q;
        while(q--){
            int cmd; cin>>cmd;
            if(cmd==0) break;
            if(cmd==1){ long long x; cin>>x; pq.push(x); }
            else if(cmd==2){
                if(pq.empty()) cout<<"Empty\n"; else { cout<<pq.top()<<"\n"; pq.pop(); }
            } else if(cmd==3){
                if(pq.empty()) cout<<"Empty\n"; else cout<<pq.top()<<"\n";
            }
        }
    }
    return 0;
}

