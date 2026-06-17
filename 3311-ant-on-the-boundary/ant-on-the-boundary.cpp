class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int pos = nums[0];
        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (pos + nums[i] == 0)
                count++;
            pos = pos + nums[i];
        }

        return count;
    }
};