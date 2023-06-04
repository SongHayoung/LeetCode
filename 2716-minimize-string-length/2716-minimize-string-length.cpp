class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> us;
        for(auto& ch : s) us.insert(ch);
        return us.size();
    }
};