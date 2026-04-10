class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size() < 3){
            return -1;
        }
        int ans = INT_MAX ;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                for (int k = j+1; k < nums.size(); k++)
                    if (nums[j] == nums[k])
                    ans = min(ans, 2*(k-i)) ;
        }
        if (ans == INT_MAX) return -1 ;
        else return ans ;

    }
};