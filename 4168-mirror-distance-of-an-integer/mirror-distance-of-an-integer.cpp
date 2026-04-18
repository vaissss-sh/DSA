class Solution {
public:
    int mirrorDistance(int n) {
        int num=n;
        int t=0;
        while(num>0){
            int d=num%10;
            t=10*t+d;
            num=num/10;
        }

        return abs(n-t);
    }
};