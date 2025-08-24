class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // complexity -> o(nlog n)+o(n)

        int n = nums.size();
        // set<int> s;
        // for(auto i:nums){
        //     s.insert(i);
        // }
        // int k= s.size();
        // int j=0;
        // for(int x:s){
        //     nums[j++]=x;
        // }
        // return k;


        // complexity-> O(N)
        int i=0;
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};