class Solution {
public:

    bool solve(int index , vector<int>& nums, int n,int target){
        if(index>=n){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }

        bool incl=solve(index+1,nums,n,target-nums[index]);
        bool excl=solve(index+1,nums,n,target);

        return incl or excl;
    }

    bool solveMem(int index , vector<int>& nums, int n,int target ,vector<vector<int>>& dp){
        if(index>=n){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool incl=solveMem(index+1,nums,n,target-nums[index],dp);
        bool excl=solveMem(index+1,nums,n,target-0,dp);

        return dp[index][target]=incl or excl;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);

        if(total & 1) return 0;

        int target=total/2;

        // return solve(0,nums,n,target);

        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return solveMem(0,nums,n,target,dp);
    }
};