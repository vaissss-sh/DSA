class Solution {
public:
    int maxi(vector<int>& piles){
        int maxii=piles[0];
        int n=piles.size();
        for(int i=1;i<n;i++){
            maxii=max(piles[i],maxii);
        }
        return maxii;
    }

    long long t_hours(vector<int>& piles, int hours){
        long long total=0;
        int n=piles.size();

        for (int i = 0; i < n; i++) {
            total+=(piles[i]/hours);
            if (piles[i] % hours != 0) {
                total++;
            }
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxi(piles);
        while(low<=high){
            int mid=(low+(high-low)/2);
            long long total=t_hours(piles,mid);
            if(total<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};