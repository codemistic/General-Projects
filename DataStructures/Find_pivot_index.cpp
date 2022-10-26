#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivot(int arr[],int n)
{int s=0;int e=n-1;
     
     int mid=(s+e)/2;
   
    while(s<e){
        
      if(arr[mid]<arr[n-1]){
           e=mid-1;mid=s+(e-s)/2;
       }
        else if(arr[mid]>arr[n-1]){
            s=mid+1;mid=s+(e-s)/2;
        }
      
        
    }
    return s;}
    int main(){
    int arr[]={6,7,9,10};
int ans=pivot(arr,5);
 
 cout<<ans;

return 0;
}
