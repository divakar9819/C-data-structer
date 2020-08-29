#include<bits/stdc++.h>
using namespace std;

/*
1. Check weather a string is palindrome or not
 Input : aabbcbbaa
output : yes
Input :aacbb
Ouput : no
*/

//Method 1:
/*
bool isPalin(string &str)
{
    int n = str.length();
    int l = 0, r = n-1;
    while(l<r){
        if(str[l]!=str[r]){
            return false;
        }
        l++;
        r--;
    }

    return true;
}

//Method 2

bool isPalin1(string &str)
{
    string str1 = str;
    reverse(str1.begin(),str1.end());
    return (str==str1);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(isPalin1(str)){
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
*/

/*
2. Check weather two  strings are anagram or not
input : str1 = apple
           str2 = pplea
output : Yes

input : str1 = developer
           str2 = peroldeva
output : No
*/

//Method 1
/*
bool isAnagram(string &str1, string &str2)
{
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    return (str1==str2);
}

//Method 2
const int CHAR = 256;
bool isAnagram1(string &s1 , string &s2)
{
    if(s1.length() != s2.length()){
        return false;
    }

    int Count[CHAR] = {0};
    for(int i=0;i<s1.length();i++){
        Count[s1[i]]++;
        Count[s2[i]]--;
    }

    for(int i=0;i<s1.length();i++){
        if(Count[s1[i]]!=0){
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string str1 , str2;
        cin>>str1;
        cin>>str2;
        if(isAnagram1(str1,str2)){
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
*/

/*
3. Leftmost repeating element
input : cabbad
output : 1
input : abcd
output : -1
*/

//Naive solution
/*
int  leftmost(string &s)
{
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(s[i]==s[j]){
                return i;
            }
        }
    }
    return -1;
}

// efficient solution
const int CHAR = 256;
int leftmost1(string &s)
{
    int count[CHAR] = {0};
    for(int i=0;i<s.length();i++){
        count[s[i]]++;
    }

    for(int i=0;i<s.length();i++){
        if(count[s[i]] > 1){
            return i;
        }
    }
    return -1;
}
//main function
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str1 ;
        cin>>str1;
        cout<<leftmost1(str1)<<endl;
    }
    return 0;
}
*/

/*
4. Leftmost not repeating element
input : cabbad
output : 0
input : abcd
output : 0
*/

//Naive solution
/*
int  leftmostNotRep(string &s)
{
    int n = s.length();
    for(int i=0;i<n;i++){
        bool flag = false;
        for( int j = 0;j<n;j++){
            if(i!=j && s[i]==s[j]){
                flag = true;
                break;
            }
        }
      if(flag==false){
        return i;
      }
    }
    return -1;
}

//Efficient solution
const int CHAR = 256;
int leftmostNotRep1(string &s)
{
    int count[CHAR] = {0};
    for(int i=0;i<s.length();i++){
        count[s[i]]++;
    }

    for(int i=0;i<s.length();i++){
        if(count[s[i]] == 1){
            return i;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string str1 ;
        cin>>str1;
        cout<<leftmostNotRep1(str1)<<endl;
    }
    return 0;
}
*/

/*
5. Reverse the words

input : I love coding
output : coding live I
input : You are good
output : good are You
*/
/*
void Reverse(string &s , int l , int r)
{
    while(l<=r){
        swap(s[l],s[r]);
        l++;
        r--;
    }
}
 void ReverseWords(string &s)
 {
     int n = s.length();
     int left = 0;
     for(int right = 0; right<n;right++){
        if(s[right] == ' '){
            Reverse(s , left , right-1);
            left = right + 1;
        }
     }

     Reverse(s, left , n-1);
     Reverse(s ,0, n-1);
 }

 void printString(string &s)
 {
     for(int i=0;i<s.length();i++){
        cout<<s[i];
     }
 }

 int main()
 {
     string s = "You are good";
     printString(s);
     cout<<endl;
     ReverseWords(s);
     printString(s);
     return 0;
 }
*/

/*
 6. Pattern searching in a string
input : str = AABAACAADAABAABA
            pattern = AABA
output : 0 , 9,12

nput : str = ABCEABEFABCD
            pattern = ABCD
output : 8

*/

// naive solution
void patSearching(string &txt , string &pat)
{
    int n = txt.length();
    int m = pat.length();
    for(int i = 0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if(j==m){
            cout<<i<<" ";
        }
    }
}

// Improvement of naive algorithm for distinct

void patSearching1(string &txt , string &pat)
{
    int n = txt.length();
    int m = pat.length();
    for(int i = 0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }


            cout<<i<<" ";
        }
        //=================
         if(j==0)
            i++;
         else
            i = (i+j);

        if(j==m){
        //====================
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string str , pat;
        cin>>str;
        cin>>pat;
        patSearching1(str , pat);
    }
    return 0;
}

