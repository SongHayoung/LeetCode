class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st{-1};
        int res = 0, i = 0;
        while(i < s.length()) {
            if(s[i] == '(') st.push_back(i);
            else {
                st.pop_back();
                if(!st.empty())
                    res = max(res, i - st.back());
                else st.push_back(i);
            }
            i++;
        }
        return res;
    }
};