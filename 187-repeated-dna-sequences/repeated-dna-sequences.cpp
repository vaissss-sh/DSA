class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<10) return {};

        vector<string> answer;
        string temp = s.substr(0, 10);
        unordered_map<string, int> count;
        count[temp]++;

        for (int i = 10; i < n; i++) {
            temp = temp.substr(1, 9);
            temp.push_back(s[i]);
            count[temp]++;
        }

        for (auto& i : count) {
            if (i.second >= 2) answer.push_back(i.first);
        }

        return answer;
    }
};