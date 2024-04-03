class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st{-1};
        int c = 0, res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push_back(i);
                c++;
            } else {
                if(c) {
                    c--;
                    st.pop_back();
                    res = max(res, i - st.back());
                } else st = {i};
            }
        }
        return res;
    }
};