class Solution {
public:
    vector<int> getRow(int rowindex) {
        vector<int> answer;
        answer.push_back(1);
        long long ans=1;
        for(int i=1;i<rowindex;i++){
                ans=ans*(rowindex-i);
                ans=ans/i;
                answer.push_back(ans);
        }
        return answer;   
    }
    vector<vector<int>> generate(int numrows) {
        vector<vector<int>> answer;
        for(int i=1;i<=numrows;i++){
            answer.push_back(getRow(i));  
        }
        return answer;
        
    }
};