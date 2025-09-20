class Solution {
public:
    bool countPartitions(vector<int> &a,int k, int maxSum) {
        int n = a.size();
        int partitions = 1;
        long long subarraySum = 0;
        for (int i = 0; i < n; i++) {
            if (subarraySum + a[i] <= maxSum) {
                subarraySum += a[i];
            }
            else {
                partitions++;
                if(partitions>k){
                    return false;
                }
                subarraySum = a[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& a, int k) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        int ans=-1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (countPartitions(a,k,mid) ) {
                ans=mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};