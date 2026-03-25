class Solution {
public:
    int solveSO(vector<int>& nums1, vector<int>& nums2,int n)
    {
        int swapp  =0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;
        // base case analysis and tabulation
        for(int index = n-1; index >=1; index--)
        {
            for(int swapped = 1; swapped >=0; swapped--)
            {
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];
                int ans = INT_MAX;
                // recursion
                if(swapped)
                swap(prev1, prev2);

               // swapping is not required if
               if(nums1[index] > prev1 && nums2[index] > prev2)
                {
                  ans = noswap;
                }
                // swapping is required if
               if(nums1[index] > prev2 && nums2[index] > prev1)
                {
                  ans = min(ans, 1+swapp);
                }

                if(swapped)
                {
                    currswap = ans;
                }
                else
                {
                    currnoswap = ans;
                }
            }
            swapp = currswap;
            noswap = currnoswap;
        }
        return min(swapp,noswap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n = nums1.size();
        return solveSO(nums1, nums2, n);
    }
};