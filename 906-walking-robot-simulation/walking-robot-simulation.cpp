class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //storing obstacles
        set<pair<int,int>> s;
        for(auto &o:obstacles){
            s.insert({o[0],o[1]});
        }

        //directions NESW
        vector<pair<int,int>> dir={
            {0,1},{1,0},{0,-1},{-1,0}
        };

        int x=0 , y=0;
        int direction=0;//north
        int maxdist=0;

        for(int i:commands){
            if(i==-1){
                direction=(direction+1)%4;
            }
            else if(i==-2){
                direction=(direction+3)%4;
            }
            else{
                //forward
                while(i--){
                    int next_x=x+dir[direction].first;
                    int next_y=y+dir[direction].second;

                    //stop when obs comes
                    if(s.count({next_x,next_y})){
                        break;
                    }

                    x=next_x;
                    y=next_y;

                    maxdist=max(maxdist,x*x+y*y);

                }
            }
        }

        return maxdist;
    }
};