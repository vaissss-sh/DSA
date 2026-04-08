class Solution {

public:
    int solve(string s1,string s2,int i,int j){
        if(i>=s1.size() || j>=s2.size())
            return 0;
        int ans=0;
        if(s1[i]==s2[j])
        {
            ans=1+solve(s1,s2,i+1,j+1);
        }
        else{
            ans=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
        }
        return ans;
    }
        int solveMem(string s1,string s2,int i,int j,vector<vector<int>> &dp){
        if(i>=s1.size() || j>=s2.size())
            return 0;
        int ans=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
        {
            ans=1+solveMem(s1,s2,i+1,j+1,dp);
        }
        else{
            ans=max(solveMem(s1,s2,i+1,j,dp),solveMem(s1,s2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int solveTab(string s1,string s2){
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        // if(i>=s1.size() || j>=s2.size())
        //     return 0;
        int ans=0;
        // if(dp[i][j]!=-1) return dp[i][j];
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                                if(s1[i]==s2[j])
                                {
                                    ans=1+dp[i+1][j+1];
                                }
                                else{
                                    ans=max(dp[i+1][j],dp[i][j+1]);
                                }
                                dp[i][j]=ans;
                                    }
        }
        return dp[0][0];
    }
    int solveSO(string s1,string s2){
        // vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        vector<int> nextR(s2.size()+1,0);
        vector<int> currR(s2.size()+1,0);
        // if(i>=s1.size() || j>=s2.size())
        //     return 0;
        int ans=0;
        // if(dp[i][j]!=-1) return dp[i][j];
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                if(s1[i]==s2[j])
                {
                    ans=1+nextR[j+1];
                }
                else{
                    ans=max(nextR[j],currR[j+1]);
                }
                currR[j]=ans;
            }
        nextR=currR;
                                
        }
        return currR[0];
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return solve(s1,s2,0,0);
        // return solveMem(s1,s2,0,0,dp);
        return solveSO(s1,s2);
    }
};
