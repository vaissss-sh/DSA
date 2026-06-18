class Solution {
public:
    int averageValue(vector<int>& nums) {
        double sum = 0;
        double totalCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 6 == 0) {
                sum += nums[i];
                totalCount++;
            }
        }

        if (totalCount == 0)
            return 0;

        return floor(sum / totalCount);
    }
};