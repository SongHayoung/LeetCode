class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = 0;
        stringstream ss;
        vector<char> st;
        for(int i = 0; i < s.length(); i++) {
            n += s[i] == '(' ? 1 : -1;
            st.push_back(s[i]);
            if(!st.empty() and n == 0) {
                for(int i = 1; i < st.size() - 1; i++)
                    ss<<st[i];
                st.clear();
            }
        }
        return ss.str();
    }
};