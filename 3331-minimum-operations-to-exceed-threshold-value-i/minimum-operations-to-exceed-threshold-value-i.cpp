class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
        for(auto it:nums){
            if(it<k){
                c++;
            }
        }
        return c;
    }
};