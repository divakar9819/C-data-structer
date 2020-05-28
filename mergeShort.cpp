#include<bits/stdc++.h>
using namespace std;

void merge(int *arr , int l , int m , int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1] , R[n2];
    int i , j , k;
    // copy left subarray
    for(i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    // copy right subarray
    for(j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

void mergeSort(int *arr , int l, int r)
{
    int m;
    if(l<r){
        m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
    
}

void printArray(int *arr , int n)
{
    int i;
    cout<<"The sorted array is : ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {38,27,43,3,9,82,10,3,1,54,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int l , r;
    l = 0;
    r = n-1;
    cout<<"hello"<<endl;
    mergeSort(arr,l,r);
    printArray(arr,n);
    return 0;
}








