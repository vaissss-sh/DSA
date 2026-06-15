class Solution {
public:
    int bulbSwitch(int n) {
        int sum = 1, i = 3, ans = 0;
        while (sum <= n) {
            sum += i;
            i += 2;
            ans++;
        }
        return ans;

    }
};