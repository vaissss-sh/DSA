class FindSumPairs {
public:

    vector<int> v1,v2;
    map<int,int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;

        //stores freq of nums2
        for(auto i:v2){
            freq[i]++;
        }


    }
    
    void add(int index, int val) {

        freq[v2[index]]--;//decrementing the old value freq

        v2[index]+=val;

        freq[v2[index]]++;//incrementing new value
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<v1.size();i++){
            int rem=tot-v1[i];
            if(freq.count(rem)>0){

                ans+=freq[rem];

            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */