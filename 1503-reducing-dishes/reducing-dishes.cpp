class Solution {
public:
    int solve(vector<int>& sat, int index, int time) {
        if (index == sat.size()) {
            return 0;
        }
        int incl = sat[index] * (time) + solve(sat, index + 1, time + 1);
        int excl = 0 + solve(sat, index + 1, time);
        return max(incl, excl);
    }

    int solvemem(vector<int>& sat, int index, int time,
                 vector<vector<int>>& dp) {
        if (index == sat.size()) {
            return 0;
        }
        if (dp[index][time] != -1) {
            return dp[index][time];
        }
        int incl = sat[index] * (time) + solvemem(sat, index + 1, time + 1, dp);
        int excl = 0 + solvemem(sat, index + 1, time, dp);
        dp[index][time] = max(incl, excl);
        return dp[index][time];
    }

    int solvetab(vector<int>& sat) {
        int n = sat.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int time = index; time >= 0; time--) {
                int incl = sat[index] * (time + 1) + dp[index + 1][time + 1];
                int excl = 0 + dp[index + 1][time];
                dp[index][time] = max(incl, excl);
            }
        }
        return dp[0][0];
    }

    int spaceopt(vector<int>& sat) {
        int n = sat.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int index = n - 1; index >= 0; index--) {
            for (int time = index; time >= 0; time--) {
                int incl = sat[index] * (time + 1) + next[time + 1];
                int excl = 0 + next[time];
                curr[time] = max(incl, excl);
            }
            next = curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        //return solve(satisfaction,0,1);

        // int n=satisfaction.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solvemem(satisfaction,0,1,dp);

        //return solvetab(satisfaction);

        return spaceopt(satisfaction);

        // int currSum = 0, total = 0;

        // for (int i = satisfaction.size() - 1; i >= 0; i--) {
        //     if (currSum + satisfaction[i] > 0) {
        //         currSum += satisfaction[i];
        //         total += currSum;
        //     } else {
        //         break;
        //     }
        // }
        // return total;
    }
};