#include <iostream>
#include <stack>
using namespace std;

// This function inserts elements
void insrt(stack<int> &s ,int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    int x=s.top();
    s.pop();
    insrt(s,ele);
    s.push(x);
    return;
}

// This function uses insrt function and reverses the stack
void reverse(stack<int>&s){
    if(s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    insrt(s,temp);
    return;
}

int main(){
    stack<int>s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.push(x);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
