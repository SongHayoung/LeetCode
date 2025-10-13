class Solution {
    bool anagram(string& a, string& b) {
        if(a.length() != b.length()) return false;
        unordered_map<char, int> counter;
        for(auto& ch : a)
            counter[ch]++;
        for(auto& ch : b)
            counter[ch]--;
        for(auto& [_, c] : counter)
            if(c) return false;
        return true;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> st;
        for(auto& w : words) {
            if(st.empty() or !anagram(st.back(), w)) {
                st.push_back(w);
            }
        }
        
        return st;
    }
};