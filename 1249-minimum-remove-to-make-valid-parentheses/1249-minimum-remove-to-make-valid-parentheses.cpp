
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> st;
        for(int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(' : st.push_back(i); break;
                case ')' : if(!st.empty()) st.pop_back(); else s[i] = '*'; break;
            }
        }
        stringstream ss;
        for(int i = 0, j = 0; i < s.length(); i++) {
            if(j < st.size() and st[j] == i) {
                j++;
            } else if(s[i] != '*') {
                ss<<s[i];
            }
        }
        return ss.str();
    }
};