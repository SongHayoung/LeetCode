
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> freq;
        for(auto& ch : s) freq[ch]++;
        int res = 0;
        for(auto& [_,cnt] : freq) {
            res += (cnt % 2 ? 1 : 2);
        }
        return res;
    }
};