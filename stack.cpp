#include<bits/stdc++.h>
using namespace std;

//Next Greater element
//I/P : 5,15,10,8,6,12,9,18
//O/P : 15,18,12,12,12,18,18,-1
/*
vector<int>nextGreaterElement(int *arr, int n)
{

    vector<int>v;
    stack<int>s;
    s.push(arr[n-1]);
    v.push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false && s.top()<arr[i]){
            s.pop();
        }
        int nextGreater = (s.empty())?(-1):(s.top());
        v.push_back(nextGreater);
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}
*/

// Previous greater Element
// I/P : 20,30,10,5,15
//O/P : -1,-1,30,10,30

/*
vector<int>previousGreaterElement(int *arr,int n)
{
    stack<int>s;
    vector<int>v;
    s.push(arr[0]);
    v.push_back(-1);
    for(int i=1;i<n;i++){
        while(s.empty()==false && s.top()<arr[i]){
            s.pop();
        }
        int previousGreater = (s.empty())?(-1):(s.top());
        v.push_back(previousGreater);
        s.push(arr[i]);
    }
    return v;
}
int main()
{

    int arr[] = {20,30,10,5,15};
    int n = sizeof(arr)/sizeof(arr[0]);
     cout<<"Original array : ";
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
     cout<<"previousGreater Element  : ";
    for(auto x:previousGreaterElement(arr,n)){
        cout<<x<<" ";
    }
    return 0;
}
*/

// Check balance paranthesis
//I/P : {([ ])}
// O/P : 1
// I/P : ((())
// O/P  : 0
/*
bool matching(char a , char b)
          {
              return((a=='{' && b=='}') || (a=='(' && b==')') || (a=='[' && b==']'));
          }
bool isBalanced(string  str)
          {
              stack<int>s;
              for(int i=0;i<str.length();i++){
                if(str[i]=='{' || str[i]=='('  || str[i]=='['){
                    s.push(str[i]);
                   }

                   else{
                    if(s.empty()==true)
                        return false;
                    else if (matching(str[i],s.top())==true)
                        return true;
                    else
                        s.pop();
                   }
              }
              return (s.empty()==true);
          }

int main()
{
    string str  ="{[()]}]";
    if(isBalanced(str)){
        cout<<"Balance"<<endl;
    }
    else{
        cout<<"not Balanced"<<endl;
    }
    return 0;
}
*/

// Reverese the item
// I/P : hello
// O/P : olleh
/*
void reverseItem(string &str)
{
    stack<char>s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    for(int i=0;i<str.length();i++){
        str[i] = s.top();
        s.pop();
    }
}

int main()
{
    string str = "Hello How are You ?";
    reverseItem(str);
    cout<<str;
    return 0;
}
*/

// Stock span Problem
// I/P : 15,13,12,14,16,8,6,4,10,30
// O/P : 1,1 1,3,5,1,1,1,4,10

// Naive solution
/*
void stockSpan(int *arr,int n)
{
    for(int i=0;i<n;i++){
        int span = 1;
        for(int j = i-1;j>=0;j--){
            if(arr[i]>=arr[j])
                span++;
            else
                break;
        }
        cout<<span<<" ";
    }
}
*/

// using stack

void stockSpan(int *arr,int n)
{
    stack<int>s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(s.empty()==false && arr[s.top()] <= arr[i])
            s.pop();
        int span = (s.empty()) ? (i+1) : (i-s.top());
        cout<<span<<" ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {15,13,12,14,16,8,6,4,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Element  : ";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Stock Span : ";
    stockSpan(arr,n);
    return 0;
}
