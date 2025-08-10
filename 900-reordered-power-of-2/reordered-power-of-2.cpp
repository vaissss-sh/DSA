class Solution {
public:
    vector<int> tofreqarray(int n){
        vector<int> freq(10,0);
        while(n>0){
            freq[n%10]++;
            n/=10;
        }
        return freq;
    }

    bool isEqualFrequency(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 10; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> target=tofreqarray(n);

        for(int i=0;i<31;i++){
            int powerof2=1<<i;
            vector<int> com=tofreqarray(powerof2);
            if (isEqualFrequency(target, com)) {
                return true;
            }
        }
        return false;

    }
};