#include<bits/stdc++.h>
using namespace std;
 void linearSearch(int *arr, int n , int item)
 {
     int i,temp=0;
     for(i=0;i<n;i++){
         if(arr[i]==item){
             temp=1;
             break;
         }
     }
     
     if(temp==1){
         cout<<"The item is found at index "<<i<<endl;
     }
     else {
         cout<<"The item is not found"<<endl;
     }
     
 }

int main()
{
    int arr[5] = {2,3,5,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int item = 7;
    linearSearch(arr,n,item);
    return 0;
}
    
    
    
    
    
    
    