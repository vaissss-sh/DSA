class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mpp;
        for(auto i:deck){
            mpp[i]++;
        }
        int x=0;
        for(auto &i:mpp){
            x=gcd(x,i.second);
            if(x<2){
                return false;
            }
        }
        return true;

    }
};