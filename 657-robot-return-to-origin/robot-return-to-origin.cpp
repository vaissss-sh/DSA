class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
        int steps=moves.length();
        for(auto i:moves){
            if(i=='U'){
                x-=1;
            }
            if(i=='D'){
                x+=1;
            }
            if(i=='L'){
                y-=1;
            }
            if(i=='R'){
                y+=1;
            }
        }
        if(x==0 && y==0){
            return true;
        }
        return false;
    }
};