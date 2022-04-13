class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> st;
        for(auto& c : s) {
            if(st.empty() || c == '(') st.push_back(c);
            else if(st.back() == '(') st.pop_back();
            else st.push_back(c);
        }
        
        return st.size();
    }
};