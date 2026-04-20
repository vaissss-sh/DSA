class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int low=0;
        int high=0;
        for (int i = 0; i < n; i++){
            if (colors[i]!=colors[n - 1]) {
                low = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--){
            if (colors[i]!=colors[0]){
                high = i;
                break;
            }
        }

        return max(n-1-low,high);

    }
};
