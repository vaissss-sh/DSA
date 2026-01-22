class Solution {
public:
    bool sorted(vector<int>& nums){
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operation=0;
        while(!sorted(nums)){
            int mini=nums[0]+nums[1];
            int index=0;

            for(int i=1;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<mini){
                    mini=sum;
                    index=i;
                }
            }
            nums[index]=mini;
            nums.erase(nums.begin()+index+1);
            operation++;
        }

        return operation;
    }

};