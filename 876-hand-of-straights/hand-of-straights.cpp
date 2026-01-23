class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0){
            return false;
        }

        //store freq of each card
        map<int,int> freq;
        for(int card:hand){
            freq[card]++;
        }

        //creating iterator pointing to beginning of freq map
        auto it=freq.begin();

        //loop
        while(it!=freq.end()){
            //skip card that is used
            if(it->second==0){
                ++it;
                continue;
            }
            int start=it->first;
            int count=it->second;
            for (int i = 0; i < groupSize; ++i) {

                // If the current required card is missing or doesn't have enough frequency
                if (freq[start + i] < count) return false;

                // Decrease the frequency for current card
                freq[start + i] -= count;
            }
            ++it;

        }

        return true;
    }
};