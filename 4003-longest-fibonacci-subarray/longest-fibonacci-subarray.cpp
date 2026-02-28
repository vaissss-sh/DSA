class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int max_count=2;
        int count=2;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-1]+nums[i-2]){
                count++;
            }
            else{
                count=2;
            }
            max_count=max(max_count,count);
        }
        return max_count;
    }
};