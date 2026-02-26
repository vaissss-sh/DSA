class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (except first bit)
        for (int i = s.size() - 1; i > 0; i--) {
            int bit = s[i] - '0';

            if (bit + carry == 1) {
                // odd → add 1 then divide
                steps += 2;
                carry = 1;
            } else {
                // even → just divide
                steps += 1;
            }
        }

        // If carry remains, add one step
        return steps + carry;
    }
};