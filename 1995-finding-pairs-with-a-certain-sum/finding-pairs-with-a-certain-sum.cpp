class FindSumPairs {
public:

    vector<int> v1,v2;
    unordered_map<int,int> freq1,freq2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;

        //stores freq of nums2 and nums1
        for(auto i:v2){
            freq2[i]++;
        }
        for(auto i:v1){
            freq1[i]++;
        }


    }
    
    void add(int index, int val) {

        freq2[v2[index]]--;//decrementing the old value freq

        v2[index]+=val;

        freq2[v2[index]]++;//incrementing new value
    }
    
    int count(int tot) {
        int ans=0;
        for(auto &[k,v]:freq1){ 
            int rem=tot-k;
            if(freq2.count(rem)>0){

                ans+=v*freq2[rem];

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