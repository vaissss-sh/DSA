class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size(); 
        int index = 0; 

        while (index + 1 < n && nums[index] < nums[index + 1])
            index++;

        if (index == n - 1)
            return 0;

        index++;
        int curr_ind = index;

        while (index + 1 < n && nums[index] < nums[index + 1])
            index++;

        
        if (index != n - 1) 
            return -1;

        if (nums[curr_ind] < nums[0] && nums[n - 1] < nums[0])
            return n - curr_ind;


        return -1;
    }
};