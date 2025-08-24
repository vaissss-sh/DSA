class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int k= s.size();
        int j=0;
        for(int x:s){
            nums[j++]=x;
        }
        return k;
    }
};