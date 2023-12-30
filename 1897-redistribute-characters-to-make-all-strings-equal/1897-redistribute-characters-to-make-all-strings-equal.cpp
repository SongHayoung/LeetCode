class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26);
        for(auto& w : words) for(auto& ch : w) freq[ch-'a'] += 1;
        for(auto& x : freq) {
            if(x % words.size()) return false;
        }
        return true;
    }
};