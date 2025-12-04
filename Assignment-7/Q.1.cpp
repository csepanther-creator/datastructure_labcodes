#include <iostream>
#include <vector>
using namespace std;

void swapv(int &a,int &b){
    int t=a; a=b; b=t;
}

void selection_sort(vector<int> &a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        swapv(a[i],a[m]);
    }
}

void insertion_sort(vector<int> &a){
    int n=a.size();
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubble_sort(vector<int> &a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swapv(a[j],a[j+1]);
        }
    }
}

void merge(vector<int> &a,int l,int m,int r){
    int n1=m-l+1, n2=r-m;
    vector<int> L(n1), R(n2);
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void merge_sort(vector<int> &a,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partition(vector<int> &a,int low,int high){
    int pivot=a[high], i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swapv(a[i],a[j]);
        }
    }
    swapv(a[i+1],a[high]);
    return i+1;
}

void quick_sort(vector<int> &a,int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quick_sort(a,low,pi-1);
        quick_sort(a,pi+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int c;
    cin>>c;
    if(c==1) selection_sort(a);
    else if(c==2) insertion_sort(a);
    else if(c==3) bubble_sort(a);
    else if(c==4) merge_sort(a,0,n-1);
    else if(c==5) quick_sort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


