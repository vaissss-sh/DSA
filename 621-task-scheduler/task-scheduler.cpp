class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char t:tasks){
            freq[t]++;
        }
        priority_queue<int> maxi;
        for (auto& entry : freq) {
            maxi.push(entry.second);
        }
        int time=0;

        while(!maxi.empty()){
            vector<int> temp;
            int cycle=n+1;
            int i=0;

            while(i<cycle && !maxi.empty()){
                int cnt=maxi.top();
                maxi.pop();

                cnt--;

                if(cnt>0){
                    temp.push_back(cnt);
                }

                time++;
                i++;
            }

            for(int v:temp){
                maxi.push(v);
            }

            if(maxi.empty()) {
                break;
            }

            time+=cycle-i;
        }

        return time;
    }
};