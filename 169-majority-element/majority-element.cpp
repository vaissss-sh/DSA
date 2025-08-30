class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore Voting Algo
        int n=nums.size();
        int count=0;
        int el;

        for(auto& i:nums){
            if(count==0){
                count=1;
                el=i;
            }
            else if(i==el){
                count++;
            }
            else{
                count--;
            }
        }

        int count1=0;
        for(auto& i:nums){
            if(i==el){
                count1++;
            }
        }
        if(count1 > (n/2)){
            return el;
        }
        return -1;
    }
};