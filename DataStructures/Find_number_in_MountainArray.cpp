#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-in-mountain-array/

int main()
{
    
  
      class MountainArray {
        public:
          int get(int index);
          int length();
      };
     

    class Solution
    {
    public:
        int findInMountainArray(int target, MountainArray &mountainArr)
        {
            int start = 0;
            int peak = 0;
            bool notFound = false;
            int end = mountainArr.length() - 1;
            int mid = (start + end) / 2;
            while (start < end)
            {
                if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                {
                    end = mid;
                    mid = start + (end - start) / 2;
                }
                if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                {
                    start = mid + 1;
                    mid = start + (end - start) / 2;
                }
            }
            peak = start;

            start = 0;
            end = peak;
            mid = (start + end) / 2;
            while (start <= end)
            {
                if (mountainArr.get(mid) > target)
                {
                    end = mid - 1;
                    mid = start + (end - start) / 2;
                }
                else if (mountainArr.get(mid) < target)
                {
                    start = mid + 1;
                    mid = start + (end - start) / 2;
                }
                else

                {
                    return mid;
                }
            }

            start = peak + 1;
            end = mountainArr.length() - 1;
            mid = (start + end) / 2;

            while (start <= end)
            {
                if (mountainArr.get(mid) < target)
                {
                    end = mid - 1;
                    mid = start + (end - start) / 2;
                }
                else if (mountainArr.get(mid) > target)
                {
                    start = mid + 1;
                    mid = start + (end - start) / 2;
                }
                else
                    return mid;
            }

            //    }
            return -1;
        }
    };

    return 0;
}
