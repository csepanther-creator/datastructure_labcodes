#include <iostream>
#include <vector>
using namespace std;

void heapify_max(vector<long long>& a, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i){ swap(a[i], a[largest]); heapify_max(a, n, largest); }
}

void heapify_min(vector<long long>& a, int n, int i){
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] < a[smallest]) smallest = l;
    if(r < n && a[r] < a[smallest]) smallest = r;
    if(smallest != i){ swap(a[i], a[smallest]); heapify_min(a, n, smallest); }
}

void heapsort_increasing(vector<long long>& a){
    int n = a.size();
    for(int i = n/2 - 1; i >= 0; --i) heapify_max(a, n, i);
    for(int i = n-1; i > 0; --i){ swap(a[0], a[i]); heapify_max(a, i, 0); }
}

void heapsort_decreasing(vector<long long>& a){
    int n = a.size();
    for(int i = n/2 - 1; i >= 0; --i) heapify_min(a, n, i);
    for(int i = n-1; i > 0; --i){ swap(a[0], a[i]); heapify_min(a, i, 0); }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int c; cin>>c;
    if(c==1) heapsort_increasing(a);
    else heapsort_decreasing(a);
    for(int i=0;i<n;i++){ if(i) cout << " "; cout << a[i]; }
    cout << "\n";
    return 0;
}

