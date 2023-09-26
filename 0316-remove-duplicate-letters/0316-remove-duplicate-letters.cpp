class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26,0);
        vector<bool> has(26,0);
        for(auto ch : s) count[ch-'a']++;
        string st = "";
        for(auto ch : s) {
            if(has[ch-'a']) {
                count[ch-'a']--;
                continue;
            }
            while(st.length() and st.back() >= ch and count[st.back()-'a'] != 0) {
                has[st.back()-'a'] = false;
                st.pop_back();
            }
            st += ch;
            count[ch-'a']--;
            has[ch-'a']= true;
        }
        return st;
    }
};