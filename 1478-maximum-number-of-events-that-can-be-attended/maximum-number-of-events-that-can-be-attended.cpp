class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end());

        priority_queue<int,vector<int>,greater<int>>pq;

        int day=events[0][0];
        int i=0;
        int count=0;//result 

        while(!pq.empty() || i<n){
            if (pq.empty()) {
                day = events[i][0];
            }
            while(i<n && events[i][0]<=day){
                pq.push(events[i][1]);
                i++;
            }
            pq.pop();
            count++;

            day++;

            //skip those days whose endday<day

            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }

        return count;

    }
};