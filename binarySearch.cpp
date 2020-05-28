#include<bits/stdc++.h>
using namespace std;
// using iteration
/*
int binarySearch(int *arr , int l, int r, int item)
{
    while(r>=l){
        int mid = l + (r - l)/2;
        if(arr[mid]==item)
            return mid;
        if(arr[mid]>item)
            return r = mid - 1;
        else
            return l = mid + 1;
        
    }
    return -1;
    
}
*/

// using recursion

int binarySearch(int *arr , int l , int r,int item)
{
    //int mid ;
    if(r>=l){
      int mid = l + (r-l)/2;
    
      if(arr[mid]==item)
        return mid;
      if(arr[mid]<item)
        return binarySearch(arr,mid+1,r,item);
    
      return binarySearch(arr,l,mid-1,item);  
    }
    return -1;
}
int main()
{
    int arr[10] = {2,3,5,7,9,12,24,56,67,98};
    int n = sizeof(arr)/sizeof(arr[0]);
    int item = 67;
    int l = 0,r = n-1; 
    cout<<binarySearch(arr,l,r,item)<<endl;
    return 0;
}