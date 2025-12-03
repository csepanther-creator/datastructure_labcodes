
#include <iostream>
#include <set>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    set<int> distinctElements;
    for (int i = 0; i < n; i++) {
        distinctElements.insert(arr[i]);
    }
    cout << "Number of distinct elements: " << distinctElements.size() << endl;
    return 0;
}

