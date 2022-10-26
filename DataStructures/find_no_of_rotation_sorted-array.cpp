
#include <bits/stdc++.h>
//https://practice.geeksforgeeks.org/problems/rotation4723/1/# 
using namespace std;


class Solution{
public:	
	int findKRotation(int arr[], int n) {
	      int start=0;
        int end=n-1;
     //   int mid=(start+end)/2;
        while (start<=end)
        {       int   mid=start + (end-start)/2;

            if(mid<n-1 && arr[mid]>arr[mid+1]){
                return (mid)+1;
            }
           else if(mid>0 && arr[mid]<arr[mid-1]){
                return (mid-1 )+1;
            }
        else    if(arr[mid]<arr[start]){
                end=mid-1;
            }
        else{
                start=mid+1;
            }
            /* code */
        }
       return 0; 
	    // code here
	}

};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  