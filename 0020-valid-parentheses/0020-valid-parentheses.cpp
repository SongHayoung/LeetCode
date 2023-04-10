class Solution {
public:
    bool isValid(string s) {
        map<char, char> pair = {
            {'}', '{'}, {']','['}, {')','('}
        };
        vector<char> st;
        for(auto ch : s) {
            if(pair.count(ch)) {
                if(st.empty() || st.back() != pair[ch]) return false;
                st.pop_back();
            } else st.push_back(ch);
        }
        return st.empty();
    }
};