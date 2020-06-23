#include<bits/stdc++.h>
using namespace std;

// Program to return a list of integer with value less than k
/*
vector<int>fun(int *arr , int n,int k)
{
    vector<int> v;
    for(int i=0;i<n;i++){
        if(arr[i]<k){
            v.push_back(arr[i]);
        }
    }
    return v;
}

int main()
{
    int arr[] = {17,10,20,13,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 15;
    for(auto x:fun(arr,n,k)){
        cout<<x<<" ";
    }
    return 0;
}
*/

// Sort student by Marks

// Sort by first element
/*
 void sortStudent(int roll_no[],int marks[],int n)
 {
     vector<pair<int , int>> vp;
     for(int i=0;i<n;i++){
        vp.push_back(make_pair(marks[i],roll_no[i]));
     }
     sort(vp.begin(),vp.end());
     cout<<"Marks      "<<"Roll No"<<endl;
     for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<<"          "<<vp[i].second<<endl;
     }
 }
*/

// Sort increasing order
/*
bool sortbysec(const pair<int,int> &p1 , const pair<int,int> p2)
{
    return p1.second <p2.second;
}

void sortStudent(int roll_no[],int marks[],int n)
 {
     vector<pair<int , int>> vp;
     for(int i=0;i<n;i++){
        vp.push_back(make_pair(roll_no[i],marks[i]));
     }

     sort(vp.begin(),vp.end(),sortbysec);

     cout<<"Roll No      "<<"Marks"<<endl;
     for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<<"          "<<vp[i].second<<endl;
     }
 }
*/

// Sort decreasing order
/*
bool sortbysec(const pair<int,int> &p1 , const pair<int,int> p2)
{
    return p1.second > p2.second;
}

void sortStudent(int roll_no[],int marks[],int n)
 {
     vector<pair<int , int>> vp;
     for(int i=0;i<n;i++){
        vp.push_back(make_pair(roll_no[i],marks[i]));
     }

     sort(vp.begin(),vp.end(),sortbysec);

     cout<<"Roll No      "<<"Marks"<<endl;
     for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<<"          "<<vp[i].second<<endl;
     }
 }
 int main()
 {

     int roll_no[] = {17,20,15,1,5};
     int marks[] = {80,75,93,78,84};
     int n = sizeof(marks)/sizeof(marks[0]);
     sortStudent(roll_no,marks,n);
     return 0;
}
*/

// Program to keep track of previous indexes after sorting a vector

void sortPreviousIndex(int *arr , int n)
{

    vector<pair<int,int>>vp;
    for(int i=0;i<n;i++){
        vp.push_back(make_pair(arr[i],i));
    }

    cout<<"Before sorting the element"<<endl;
    cout<<"Number    "<<"Index"<<endl;
    for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<<"    "<<vp[i].second<<endl;
    }

    sort(vp.begin(),vp.end());

    cout<<" Sorting Number     "<<"Index"<<endl;
    for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<<"   "<<vp[i].second<<endl;
    }
}

int main()
{

    int arr[] = {2,5,3,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortPreviousIndex(arr,n);
    return 0;
}



