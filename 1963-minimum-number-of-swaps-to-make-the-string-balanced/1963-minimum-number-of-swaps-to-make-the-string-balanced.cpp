class Solution {
public:
    int minSwaps(string s) {
        vector<char> st;
        for(auto& ch : s) {
            if(!st.empty() and st.back() == '[' and ch == ']') st.pop_back();
            else st.push_back(ch);
        }
        return (st.size() / 2 + 1) / 2;
    }
};