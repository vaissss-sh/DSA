class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i:arr){
            freq[i]++;
        }

        int maxi=-1;

        for(auto [num,count]:freq){
            if(num==count){
                maxi=max(maxi,num);
            }
        }
        return maxi;
    }
};