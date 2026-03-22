class Solution {
public:


    int solveRec(int index,int endIndex, vector<int>&nums, int n){
        if(n == 0 || index > endIndex){
            return 0;
        }
        int include = nums[index] + solveRec(index + 2,endIndex, nums, n - 1);
        int exclude = 0 + solveRec(index + 1,endIndex, nums, n);
        return max(include, exclude);
    }


    int solveMem(int index, int endIndex, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(n == 0 || index > endIndex){
            return 0;
        }
        if(dp[index][n] != -1){
            return dp[index][n];
        }

        int include = nums[index] + solveMem(index + 2,endIndex, nums, n - 1, dp);
        int exclude = 0 + solveMem(index + 1,endIndex, nums, n, dp);
        return dp[index][n] = max(include, exclude);
    }

    //TABULATION
    int solveTab(vector<int>& nums){
        int k = nums.size();
        vector<vector<int>>dp1(k + 2, vector<int>(k + 2, 0));
        for(int index = k - 2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int include = nums[index] + dp1[index + 2][n - 1];//solveMem(index + 2,endIndex, nums, n - 1, dp);
                int exclude = 0 + dp1[index + 1][n];//solveMem(index + 1,endIndex, nums, n, dp);
                return dp1[index][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][k/3];


        vector<vector<int>>dp2(k + 2, vector<int>(k + 2, 0));
        for(int index = k - 1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int include = nums[index] + dp2[index + 2][n - 1];//solveMem(index + 2,endIndex, nums, n - 1, dp);
                int exclude = 0 + dp2[index + 1][n];//solveMem(index + 1,endIndex, nums, n, dp);
                return dp2[index][n] = max(include, exclude);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }

    int solve(vector<int>&nums){
        int k = nums.size();
        vector<int>prev1(k + 2, 0);
        vector<int>curr1(k + 2, 0);
        vector<int>next1(k + 2, 0);

        for(int index = k - 2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int include = nums[index] + next1[n - 1];//solveMem(index + 2,endIndex, nums, n - 1, dp);
                int exclude = 0 + curr1[n];//solveMem(index + 1,endIndex, nums, n, dp);
                prev1[n] = max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k/3];
        

        vector<int>prev2(k + 2, 0);
        vector<int>curr2(k + 2, 0);
        vector<int>next2(k + 2, 0);

        for(int index = k-1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int include = nums[index] + next2[n - 1];//solveMem(index + 2,endIndex, nums, n - 1, dp);
                int exclude = 0 + curr2[n];//solveMem(index + 1,endIndex, nums, n, dp);
                prev2[n] = max(include, exclude);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];
        return max(case1, case2);
    }
    int maxSizeSlices(vector<int>& nums) {
        //int k = nums.size();
        //There will  be 2 cases
        //where you will start from the first index, if you start with 1, you will not able to eat 6th index one
        //2nd case
        //where you will not choose 1st, so you will able to choose 6th
        //then return the max of them

        //RECURSION

        // int case1 = solveRec(0, k - 2, nums, k/3);
        // int case2 = solveRec(1, k - 1,  nums, k/3);
        // return max(case1, case2);
        
        //MEMORISATION
        // vector<vector<int>>dp1(k + 1, vector<int>(k, -1));
        // int case1 = solveMem(0, k-2, nums, k/3, dp1);
        // vector<vector<int>>dp2(k + 1, vector<int>(k, -1));
        // int case2 = solveMem(1, k-1, nums, k/3, dp2);

        // return max(case1, case2);


        return solve(nums);
    }
};