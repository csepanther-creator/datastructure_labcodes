#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin >> n)) return 0;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int left = 0, right = n - 1;
    while(left < right) {
        int minIdx = left, maxIdx = left;
        for(int i = left; i <= right; ++i) {
            if(a[i] < a[minIdx]) minIdx = i;
            if(a[i] > a[maxIdx]) maxIdx = i;
        }
        swap(a[left], a[minIdx]);
        if(maxIdx == left) maxIdx = minIdx;
        swap(a[right], a[maxIdx]);
        ++left; --right;
    }
    for(int i = 0; i < n; ++i) {
        if(i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}

