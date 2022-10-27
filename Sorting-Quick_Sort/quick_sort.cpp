#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void quickSort(vector <int> &arr,int s,int e){
    if(s>=e)
    return;
    int pivot=arr[s];
    int count=0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<pivot)
        count++;
        /* code */
    }
    int partition_index=s+count;
    swap(arr[s],arr[partition_index]);
    int i=s;
    int j=e;
    while (i< partition_index && j>partition_index )
    {
       while (arr[i]<arr[partition_index])
       { 
        i++;
        /* code */
       }
       while (arr[j]> arr[partition_index]){
       
        j--;}
        swap(arr[i++],arr[j--]);

        /* code */
    }
    
    quickSort(arr,s,partition_index-1);
    quickSort(arr,partition_index+1,e);
    
}
    int main(){
 vector <int>  arr={422,8,5,44,9,9,42,81,22};
    int n=arr.size();
   

    quickSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }
    

 
 

return 0;
}
