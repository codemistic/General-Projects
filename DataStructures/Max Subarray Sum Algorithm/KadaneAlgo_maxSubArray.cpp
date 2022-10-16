#include <bits/stdc++.h>
using namespace std;

// kadane Algorithm,the following 3 steps are the underlining algorithm

/* 1.Calculate sum=curr_sum+arr[i] for every iteration
 2.Update max. sum for every iteration .
 3.if sum<0 set sum=0*/

// Time complexity:O(n)

int kadane(int arr[], int &n)
{
    int currentsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentsum += arr[i];
        maxsum = max(currentsum, maxsum);

        if (currentsum < 0)
        {
            currentsum = 0;
        }
    }
    return maxsum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = kadane(arr, n);
    cout << "Maximum Sum:" << ans << endl;

    return 0;
}