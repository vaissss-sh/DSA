class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxLen = 0;
        int i = 0;

        while (i < n) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int j = i;
                while (j + 1 < n && nums[j + 1] <= threshold && (nums[j] % 2 != nums[j + 1] % 2)) {
                    j++;
                }
                maxLen = max(maxLen, j - i + 1);
                i = j + 1;
            } else {
                i++;
            }
        }
        return maxLen;
    }
};