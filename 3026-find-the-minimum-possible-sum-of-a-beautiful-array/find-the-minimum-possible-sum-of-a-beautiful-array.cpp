class Solution {
public:
    int mod=1e9+7;
    int minimumPossibleSum(int n, int target) {
        // set<int> st;
        // long long ans = 0;
        // for(int i = 1; st.size() < n; ++i ){
        //     if(st.find(target - i) == st.end()) { st.insert(i); ans += i; }
        // }
        // return ans % mod;


        int x = target/2;
        long long ans =0;
        for(int i=1;i<=x;i++){        
            ans+=i;
            n--;
            if(n==0){
                break;
            }
        }
        int z = target;
        while(n--){
            ans+=z;
            z++;
        }
        return ans % mod;
    }
};