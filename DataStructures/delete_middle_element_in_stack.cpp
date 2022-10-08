#include <iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);
    return;
}
stack<int> del_middle(stack<int>&s,int n){
    if(s.size()==0){
        return s;
    }
    int k=(s.size()/2)+1;
    solve(s,k);
    return s;
}
int main(){
    stack<int>s;
    stack<int>x;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        s.push(i);
    }
    x=del_middle(s,n);
    while(!x.empty()){
        cout<<x.top()<<" ";
        x.pop();
    }

    return 0;
}
