class Solution {
public:
    bool isValid(string s) {
        string st = "";
        for(auto& ch : s) {
            st.push_back(ch);
            int sz = st.size();
            if(sz >= 3 and st[sz-1] == 'c' and st[sz-2] == 'b' and st[sz-3] == 'a') {
                st.pop_back();
                st.pop_back();
                st.pop_back();
            }
        }
        return st == "";
    }
};