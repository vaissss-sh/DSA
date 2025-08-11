class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i=0;i<31;i++){
            if((1<<i) & n ){
                powers.push_back(i);
            }
        }

        vector<int> ans;
        int mod=1e9+7;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            long long multi=1;
            for(int j=l;j<=r;j++){
                multi=(multi* (1<< powers[j]))%mod;
            }
            ans.push_back(multi);
        }
        return ans;
    }
};