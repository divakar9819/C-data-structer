#include<bits/stdc++.h>
using namespace std;
//using recursion

int ternarySearch(int *arr ,int l,int r,int item)
{
    if(r>=l){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(arr[mid1]==item)
            return mid1;
        if(arr[mid2]==item)
            return mid2;
        if(arr[mid1]<item)
            return ternarySearch(arr,mid1+1,r,item);
        if(arr[mid2]>item)
            return ternarySearch(arr,l,mid2-1,item);
        return ternarySearch(arr,mid1+1,mid2-1,item);
            
            
    }
    return -1;
}

int main()
{
    int arr[10] = {2,3,5,7,9,12,24,56,67,98};
    int n = sizeof(arr)/sizeof(arr[0]);
    int item = 2;
    int l = 0,r = n-1; 
    cout<<ternarySearch(arr,l,r,item)<<endl;
    return 0;
}