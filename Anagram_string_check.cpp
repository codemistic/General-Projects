#include <bits/stdc++.h>
using namespace std;

// Method 1
bool anagram(string &s1, string &s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return (s1==s2);
}

// Method 2
const int x=256;
bool areanagram(string &s1,string &s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    int count[x]={0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0;i<s1.length();i++){
        if(count[i]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1;
    string s2;
    cout<<"Enter String s1: ";
    cin>>s1;
    cout<<"Enter String s2: ";
    cin>>s2;
    cout<<areanagram(s1,s2);
    return 0;
}
