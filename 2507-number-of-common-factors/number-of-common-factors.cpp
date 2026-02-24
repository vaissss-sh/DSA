class Solution {
public:
    int commonFactors(int a, int b) {
        int minval = min(a, b);
        int count = 0;
        for(int i = 1; i <= minval; i++){
            if(a % i == 0 && b % i == 0){
                count++;
            }
        }
        return count;
    }
};