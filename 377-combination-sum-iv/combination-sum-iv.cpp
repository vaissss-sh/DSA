class Solution {
public:
    int solve(vector<int>& nums, int target){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }

        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=solve(nums,target-nums[i]);
        }
        return sum;
    }

    int solvemem(vector<int>& nums, int target,vector<int>& dp){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }

        if(dp[target]!=-1){
            return dp[target];
        }

        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=solvemem(nums,target-nums[i],dp);
        }
        dp[target]=sum;
        return dp[target];
    }

    int solveTab(vector<int> &nums, int target){

        vector<unsigned int> dp(target + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= target; i++){

            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0)
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];

    }
    int combinationSum4(vector<int>& nums, int target) {
        //vector<int>dp(target+1,-1);
        //return solvemem(nums,target,dp);

        return solveTab(nums,target);
    }
};