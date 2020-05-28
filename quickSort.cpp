#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int low , int high )
{
    int i , j,pivot;
    pivot = arr[high];
    i = (low - 1);
    for(j=low;j<high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],arr[j]);
        }

    }
    
    swap(&arr[i+1],&arr[pivot]);
    return (i+1);
    
}

void quickSort(int *arr , int low , int high)
{
    if(low<high){
        int pi;
        pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
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
    int arr[] = {12,6,3,18,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low,high;
    low = 0;
    high = n-1;
    quickSort(arr,low,high);
    printArray(arr,n);
    return 0;
}


