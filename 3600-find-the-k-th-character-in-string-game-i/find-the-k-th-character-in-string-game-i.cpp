class Solution {
public:
    char kthCharacter(int k) {
        // string s="a";
        // while(s.size()<k){
        //     string t="";
        //     for(int i=0;i<s.size();i++){
        //         t+=(s[i]+1);
        //     }
        //     s+=t;
        // }

        // return s[k-1];

        // one liner solution

        int x=__builtin_popcount(k-1); // generates no. of 1 in binary form
        return 'a'+x;
    }
};