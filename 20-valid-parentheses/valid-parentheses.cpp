class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto el:s){
            if(el == '{' || el == '[' || el == '(')
            st.push(el);
            else if(st.empty())
                return false;
            else{
                auto last_element = st.top();
                if(el == '}' && last_element != '{')
                    return false;
                if(el == ')' && last_element != '(')
                    return false;
                if(el == ']' && last_element != '[')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};