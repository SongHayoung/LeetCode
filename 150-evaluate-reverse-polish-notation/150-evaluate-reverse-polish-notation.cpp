class Solution {
    
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for(auto& token : tokens) {
            if(token == "+") {
                int n = st.back(); st.pop_back();
                st.back() += n;
            } else if(token == "-") {
                int n = st.back(); st.pop_back();
                st.back() -= n;
            } else if(token == "*") {
                int n = st.back(); st.pop_back();
                st.back() *= n;
            } else if(token == "/") {
                int n = st.back(); st.pop_back();
                st.back() /= n;
            } else {
                st.push_back(stoi(token));
            }
        }
        return st[0];
    }
};