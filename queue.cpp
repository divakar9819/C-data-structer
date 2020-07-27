#include<bits/stdc++.h>
using namespace std;

/*
int main()
{
    queue<int>q;
    q.push(4);
    q.push(6);
    q.push(8);
    cout<<q.size()<<endl;
    while(q.empty()==false){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
*/

//Generate a number using given digit
//   I/P :- N = 4 , digit ={5,6}
//   O/P :- {5,6,55,56}
/*
int main()
{
    queue<string> q;
    int N ;
    string curr;
    cin>>N;
    q.push("5");
    q.push("6");
    for(int i = 0;i<N;i++){
        curr  = q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr +"5");
        q.push(curr +"6");

    }
    return 0;
}
*/

// Reverse first k item of a queue
//I/P :- 10,20,30,40,50  k = 3
//O/P :- 30 , 20,10,40,50

/*
void ReverseKItem(queue<int>&q , int k)
{
    if(q.empty()==true || k > q.size() || k<0){
        return ;
    }
    stack<int>s;
    //int item,ele,e;
    //cout<<q.size();
    //pushing element in the stack;
    for(int i=0;i<k;i++){
        s.push( q.front());
        q.pop();
    }

    //push element from stack to queue
    while(s.empty()==false){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }



}

int main()
{
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
    }
    ReverseKItem(q,k);
    cout<<q.size()<<endl;
    for(int i=0;i<=q.size();i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;

}
*/

// Introduction of priority_queue
/*
int main()
{
    // by default Max Heap
    //priority_queue<int>pq;
    //priority_queue<int , vector<int> , greater<int>> pq; // Min Heap
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    priority_queue<int , vector<int> , greater<int>> pq(arr , arr+n);
    //pq.push(10);
    //pq.push(20);
    //pq.push(30);

    cout<<pq.size()<<endl;
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
*/

//Sorting an array using priority queue
/*
void sortArray(int *arr , int n)
{
    //Using max heap
    /*
    priority_queue<int>pq(arr , arr+n);
    for(int i= n-1;i>=0;i--){
        arr[i] = pq.top();
        pq.pop();
    }
    */

    //Using min Heap
    /*
    priority_queue<int , vector<int> , greater<int>>pq(arr , arr+n);
    for(int i=0;i<n;i++){
        arr[i] = pq.top();
        pq.pop();
    }
}

void printArray(int *arr , int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

*/

//find k largest element in an array
//Method -1
/*
void KLargest(int *arr , int n , int k)
{
    sort(arr , arr+n);
    for(int i = n-1;i>=n-k;i--){
        cout<<arr[i]<<" ";
    }
}
*/

//Method -2
/*
void KLargest(int *arr , int n , int k)
{
    priority_queue<int>pq(arr , arr+n);
    for(int i=0;i<k;i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
*/

//Method - 3
/*
void KLargest(int *arr , int n , int k)
{
    priority_queue<int , vector<int> , greater<int>>pq(arr , arr+k);
    for(int i=k;i<n;i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
*/

//Kth Largest element
/*
void KthLargest(int *arr , int n , int k)
{
    sort(arr , arr+n);
    cout<<arr[n-k]<<endl;
}
*/
/*
void KthLargest(int *arr , int n , int k)
{
    priority_queue<int>pq(arr , arr+n);
    for(int i=1;i<k;i++){
        pq.pop();
    }
    cout<<pq.top()<<endl;
    pq.pop();
}

int main()
{
    int arr[] = {10,5,1,12,8,20,2,4,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    KthLargest(arr,n,k);
    return 0;
}
*/

/* Given an array of price of item we need to find the maximum count of item that
     we can purchase with given money
     I/P : cost = { 1 ,12 , 5 , 111 , 200}
     sum = 10
     O/P : 2
*/

//Method - 1
/*
void purchaseMax(int *arr , int n , int sum)
{
    int i = 0 , res = 0;
    sort(arr , arr+n);
    while((sum - arr[i]) >=0){
        sum = sum - arr[i];
        i++;
        res++;
    }
    cout<<res<<endl;
}
*/

//Method - 2
/*
int PurchaseMax(int *arr , int n , int sum)
{
    int res = 0;
    priority_queue<int , vector<int> , greater<int>>pq(arr , arr+n);
    while(sum >=0 && pq.top()<=sum && pq.empty()==false){
        sum = sum - pq.top();
        pq.pop();
        res++;
    }
    return res;
}
int main()
{
    int arr[] = {1,12,5,111,4,200};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 1;
    cout<<PurchaseMax(arr , n , sum)<<endl;
    return 0;
}
*/
/*
Find k most frequent element
I/P : 10,5,20,5,10,10,30
k = 2
O/P : 10 , 5
*/

//Method - 1
/*
bool myComp(pair<int , int>p1 , pair<int,int>p2)
{
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

void mostKFrequent(int *arr , int n , int k)
{
    unordered_map<int ,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    vector<pair<int , int>>vp(m.begin() , m.end());
    sort(vp.begin() , vp.end(),myComp);
    for(int j=0;j<k;j++){
        cout<<vp[j].first<<" ";
    }
}
*/

/*
// Not working
struct myComp{

   bool operator()(pair<int,int>p1 , pair<int,int>p2)
   {
       if(p1.second == p2.second){
        return p1.first > p2.first;
       }
       return p1.second < p2.second;
   }
};

void mostkFrequent(int *arr , int n , int k)
{
    unordered_map<int , int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    priority_queue<pair<int,int> ,vector<int,int>> ,myComp>pq(m.begin(),m.end());
    for(int j=0;j<k;j++){
        cout<<pq.top().first <<" ";
        pq.pop();
    }
}
int main()
{
    //int arr[] = {10,5,20,5,10,10,30};
    int arr[] = {20,40,30,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    mostKFrequent(arr , n , k);
    return 0;
}
*/

/*
Ceiling of every item on Right
I/P :-  {10,100,200,30,120,120}
O/P :- 30,120,-1,120,120,-1
*/
//Method - 1
/*
void CeilingRight(int *arr , int n)
{
   for(int i=0;i<n;i++){
    int diff = INT_MAX;
    for(int j = i+1;j<n;j++){
        if(arr[i] < arr[j]){
            diff = min(diff , arr[j]-arr[i]);
        }
    }
    if(diff == INT_MAX){
        cout<<-1<<" ";
    }
    else {
        cout<<arr[i] + diff<<" ";
    }
   }
}
*/

void CeilingRight(int *arr , int n)
{
    set<int>s;
    int res[n];
    for(int i=n-1;i>=0;i--){
        auto it = s.lower_bound(arr[i]);
        if(it == s.end()){
            res[i] = -1;
        }
        else{
            res[i] = *it;
        }
        s.insert(arr[i]);

    }

    for(int j=0;j<n;j++){
        cout<<res[j]<<" ";
    }
}
int main()
{
    //int arr[] = {10,100,200,30,120,120};
    //int arr[] = {10,20,30,40};
    //int arr[] = {40,30,20,10};
    int arr[] = {100,50,30,60,55,32};
    int n = sizeof(arr)/sizeof(arr[0]);
    CeilingRight(arr , n);
    return 0;
}
