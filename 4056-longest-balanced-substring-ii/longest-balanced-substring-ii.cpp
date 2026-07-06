class Solution {
public:
    int three(string s) {
        map<pair<int,int>, int> firstSeen;

        int countA = 0, countB = 0, countC = 0;
        int ans = 0;

        firstSeen[{0, 0}] = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;

            int d1 = countA - countB;
            int d2 = countA - countC;

            pair<int,int> state = {d1, d2};

            if (firstSeen.count(state)) {
                ans = max(ans, i - firstSeen[state]);
            } else {
                firstSeen[state] = i;
            }
        }

        return ans;
    }
    int two(string &s,char x,char y){
        int res=0;
        int i=0;
        int n=s.size();
        while(i<n){
            while(i<n && s[i]!=x && s[i]!=y) i++;
    
            unordered_map<int, int> pos;
            pos[0] = i - 1;
            int diff = 0;

            while (i < n && (s[i] == x || s[i] == y)) {
                diff += (s[i] == x ? 1 : -1);
                if (pos.count(diff))
                    res = max(res, i - pos[diff]);
                else
                    pos[diff] = i;

                i++;
            }
        }
        return res;
    }
    int one(string &s){
        int maxi=0;
        int i=0;
        int n=s.size();
        while(i<n){
            int j=i;
            while(j<n && s[j]==s[i]){
                j++;
            }
            maxi=max(maxi,j-i);
            i=j;
        }
        return maxi;
    }
    int longestBalanced(string s) {
        int ans=0;
        ans=max(ans,one(s));

        ans=max(ans,two(s,'a','b'));
        ans=max(ans,two(s,'a','c'));
        ans=max(ans,two(s,'b','c'));

        ans=max(ans,three(s));
        return ans;
    }
};