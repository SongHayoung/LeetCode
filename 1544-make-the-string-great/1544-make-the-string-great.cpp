class Solution {
public:
    string makeGood(string s) {
        string st = "";
        for(auto ch : s) {
            if(st.empty()) st.push_back(ch);
            else if(islower(ch) and st.back() == toupper(ch)) st.pop_back();
            else if(isupper(ch) and st.back() == tolower(ch)) st.pop_back();
            else st.push_back(ch);
        }
        return st;
    }
};