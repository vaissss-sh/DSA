class Solution {
public:
    int solve(vector<int>& nums, int target){
        if(target==0){
            return 0;
        }

        if(target<0) return INT_MAX;

        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int ans=solve(nums,target-nums[i]);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }
        return mini;
    }

    int solveTab(vector<int>& coins, int target){
        vector<int> dp(target+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i<=target; i++){
            for(int j = 0; j<coins.size(); j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
        }
        if(dp[target] == INT_MAX) return -1;
        else return dp[target];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins, amount);
        // if(ans == INT_MAX) return -1;
        // else return ans;

        return solveTab(coins,amount);

    }
};