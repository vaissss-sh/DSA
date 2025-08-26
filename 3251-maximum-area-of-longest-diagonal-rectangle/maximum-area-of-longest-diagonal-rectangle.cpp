class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_dia = 0; 
        int maxArea = 0;

        for (auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diagSq = l * l + w * w;
            int area = l * w;
            if (diagSq > max_dia || (diagSq == max_dia && area > maxArea)) {
                max_dia = diagSq;
                maxArea = area;
            }
        }

        return maxArea;

        // for(int i=0;i<dimensions.size();i++){
        //     ans=(dimensions[i][0]*dimensions[i][0]) + (dimensions[i][1]*dimensions[i][1]);
        //     if(ans>=maxi){
        //         maxi=ans;
        //         d1=dimensions[i][0];
        //         d2=dimensions[i][1];
        //     }
        // }
        // return d1*d2;
    }
};