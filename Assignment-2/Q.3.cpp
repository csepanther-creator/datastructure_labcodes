

#include <iostream>
using namespace std;

int missingNumberLinear(int arr[], int size, int n) {
    int total = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return total - sum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};  
    int n = 6; 
    int missing = missingNumberLinear(arr, n - 1, n);
    cout << "Missing number (linear): " << missing << endl;
    return 0;
}


#include <iostream>
using namespace std;

int missingNumberBinary(int arr[], int low, int high) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] != mid + 1) {
        if (mid == 0 || arr[mid - 1] == mid)
            return mid + 1;
        return missingNumberBinary(arr, low, mid - 1);
    }
    return missingNumberBinary(arr, mid + 1, high);
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int missing = missingNumberBinary(arr, 0, n - 1);
    if (missing != -1)
        cout << "Missing number (binary search): " << missing << endl;
    else
        cout << "No missing number" << endl;
    return 0;
}

