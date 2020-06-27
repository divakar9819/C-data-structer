#include<bits/stdc++.h>
using namespace std;
//#define max 100
/*
// reverse an array using auxilary pace

void reverseArrayAux(int *A , int n)
{
    int B[n],i,j;
    for(i=n-1, j=0; i>=0, j<n; i--, j++){
            B[j] = A[i];

    }
    cout<<"Reverse of array  ";
    for(i=0;i<n;i++){
        cout<<B[i]<<" ";
    }
}

void swapElement(int *a , int *b )
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int *arr , int n)
{
    int i,j;
    for(i=0,j=n-1; i<j; i++ , j--){
        swapElement(&arr[i],&arr[j]);
    }
    cout<<"Reverse array using swaping : ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// Left shift
 void leftShift(int *arr , int n)
 {
     int temp , i;
     temp = arr[0];
     for(i=1;i<n;i++){
        arr[i-1] = arr[i];
     }
    // arr[n] = temp;
     cout<<"Left shift of array ";
     for(i=0;i<n-1;i++){
        cout<<arr[i]<<" ";
     }
 }

 // Check weather an array is sorted or not
 int isSorted(int *arr , int n)
 {
     int i;
     for(i=0;i<n;i++){
        if(arr[i] > arr[i+1]){
            return 0;
            break;
        }
     }
     return 1;
 }

 // Insert an element in sorted array

 void insertSorted(int *arr , int n,int item)
 {
     int i ;
     i = n-1;
     while(arr[i]>item){
        arr[i+1] = arr[i];
        i--;
     }
     arr[i+1] = item;
     for(i=0;i<n+1;i++){
        cout<<arr[i]<<" ";
     }
 }

int main()
{
    int A[7] = {8,13,20,25,28,33};
    int n = sizeof(A)/sizeof(A[0]);
   // cout<<n;
    //reverseArrayAux(A,n);
   // cout<<endl;
   // reverseArray(A,n);
   // cout<<endl;
    //leftShift(A,n);
    int k =18;
    cout<<isSorted(A,n);


    return 0;
}
*/

// Arranging an array one side negative and one side positive
/*
void swapElement(int *a , int *b )
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void arrangeArray(int *arr , int n)
{

    int i =0 , j = n-1;
    while(i<j){
        while(arr[i]<0){
            i++;
        }
        while(arr[j] >= 0){
            j++;
        }
        if (i<j){
             swapElement(&arr[i],&arr[j]);
        }



    }
    cout<<"Arranging array : ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {-6,5,33,-2,8,-9,11,-7};
    int n = sizeof(arr)/sizeof(arr[0]);
    arrangeArray(arr,n);
    return 0;
}
*/

// marge an array
/*
void mergeArray(int *arr1 , int *arr2,int m,int n)
{
    int arr3[m+n];
    int i , j,k;
    i = 0;
    j = 0;
    k = 0;
    while(i>m && j>n)
    {
        if(arr1[i]>arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    while(i<m){
        arr3[k++] = arr1[i++] ;
    }

   while(j<n){
    arr3[k++] = arr2[j++];
   }
   cout<<"The merge array is : ";
   for(i=0;i<m+n;i++){
    cout<<arr3[i]<<" ";
   }
}


int main()
{
    int arr1[] = {3,8,16,20,25};
    int arr2[] = {4,10,12,22,23};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    mergeArray(arr1,arr2,m,n);
    return 0;
}
*/

// Find missing in n natural number
/*
void missingNatural(int *arr , int n)
{
    int sum = 0,s;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
      int     s1 = arr[n-1];
    s = (s1*(s1+1))/2;
    cout<<"Missing Number is : "<<(s-sum);

}

// Find missing in n natural number when the given number is not contineous  natural number
void missing(int *arr , int n)
{
    int diff = arr[0] - 0;
    for(int i=0;i<n;i++){
        if(arr[i]-i != diff) {
            cout<<"Missing Number is : "<<diff + i ;
            break;
        }
    }
}
int main()
{
    int arr[] = {6,7,8,9,10,11,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    missing(arr,n);
    return 0;
}
*/

// Find multiple missing value in the given indax
/*
void missingMulti(int *arr , int n)
{
    int diff = arr[0] - 0;
    for(int i=0;i<n;i++){
        if(arr[i]-i != diff) {
            while(diff < arr[i]-i){
                cout<<diff+i<<" ";
                diff++;
            }

        }
    }
}

// Find missing value of unsorted array
/*
void missingUnsorted(int *arr , int n)
{
    int h = *max_element(arr , arr+n);
    int l = *min_element(arr,arr+n);
    int H[h];
    for(int i=0;i<n;i++){
        H[arr[i]]++;
    }
    for(int i=l;i<=h;i++){
        if(H[i]==0){
            cout<<i<<" ";
        }
    }
}
int main()
{
    int arr[] = {3,7,4,9,12,6,1,11,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    missingUnsorted(arr,n);
    return 0;
}
*/

// Finding duplicate in array
/*
void duplicate(int *arr , int n)
{
    int lastDuplicate = 0;
    for(int i=0;i<n;i++){
        if((arr[i] == arr[i+1])  && (arr[i] != lastDuplicate)){
                cout<<arr[i]<<" ";
                lastDuplicate = arr[i];

        }
    }
}

// counting number of duplicate and its value
void duplicateNumber(int *arr , int n)
{
    int j,i ;
    for(i=0;i<n;i++){
        if(arr[i] == arr[i+1]){
            j = i+1;
            while(arr[j]==arr[i]){
                j++;
            }
            cout<<arr[i]<<" ->"<<j-i<<" ";
             i = j-1;
        }


    }
}

int main()
{
    int arr[] = {3,6,8,8,10,12,15,15,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    duplicateNumber(arr,n);
    return 0;
}
*/

// Finding duplicate on unsorted array
/*
 void duplicateUnsorted(int *arr , int n)
 {
     int i , j,temp;
     for(i=0;i<n;i++){
        temp = 1;

            for(j=1;j<n;j++){
                if(arr[i] == arr[j]){
                    temp++;
                    arr[j] = -1;
                }
            }
        }
        if(temp>1){
          cout<<arr[i]<<" "<<temp<<endl;


     }
 }
//Finding duplicate element using hash table

void dupliateHash(int *arr , int n)
{
    int l = *min_element(arr,arr+n);
    int h = *max_element(arr,arr+n);
    //cout<<l;
    int H[h] ;
    for(int i=0;i<=h;i++){
        H[i] = 0;
    }
    //cout<<H[h];
    for(int i=0;i<n;i++){
        H[arr[i]]++;
    }

    for(int i=l;i<h;i++){
        if(H[i]>1 ){
            cout<<i<<" "<<H[i]<<endl;
        }
    }
}

int main()
{
    int arr[] = {3,6,8,8,10,4,4,4,4,12,15,15,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    duplicateUnsorted(arr,n);
    return 0;
}
*/

// Find a pair with sum k (a + b = k)

void findPair(int *arr , int n , int k)
{
    vector<pair<int,int>>vp;
    int i , j;
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            if((arr[i] + arr[j]) == k)
                vp.push_back(make_pair(arr[i],arr[j]));
        }
    }
    cout<<"Pair which equal to the given number : ";
        for(int i =0 ; i<vp.size();i++){
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }
}

int main()
{
    int arr[] = {2,3,6,7,8,9,10,14,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;
    findPair(arr,n,k);
    return 0;
}



