class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> us{'a','e','i','o','u'};
        vector<char> st;
        for(int i = 0; i < s.length(); i++) if(us.count(tolower(s[i]))) st.push_back(s[i]);
        for(int i = 0; i < s.length(); i++) if(us.count(tolower(s[i]))) {
            s[i] = st.back();
            st.pop_back();
        }
        return s;
    }
};