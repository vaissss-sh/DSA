class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i=0;i<31;i++){
            if((1<<i) & n ){
                powers.push_back(i);
            }
        }

        vector<int> pref(powers.size()+1);
        for(int i=1;i<pref.size();i++){
            pref[i]=pref[i-1]+powers[i-1];
        }

        vector<int> ans;
        int mod=1e9+7;
        vector<int> pmod(pref[pref.size()-1]+1,1);
        for(int i=1;i<pmod.size();i++){
            pmod[i]=(pmod[i-1]*2)%mod;
        }

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int sum=pref[r+1]-pref[l];
            // long long multi=1;
            // for(int j=l;j<=r;j++){
            //     multi=(multi* (1<< powers[j]))%mod;
            // }
            ans.push_back(pmod[sum]);
        }
        return ans;
    }
};