
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    int main(){
    class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count=0;
        vector<int> num;
        int i=0;int j=0;
     
        while(count<(m+n)){
         if( j==n){
                num.push_back(nums1[i]);
            i++;
           }
      else  if(nums1[i]<nums2[j] && i<m){
            num.push_back(nums1[i]);
            i++;
        }
          
        else { num.push_back(nums2[j]);
            j++;}
        count++;    
    }
    nums1=num;}
};

 
 

return 0;
}
