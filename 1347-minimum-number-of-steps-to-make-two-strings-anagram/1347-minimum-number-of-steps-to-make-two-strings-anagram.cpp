class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> freq;
        for(auto& ch : s) freq[ch]++;
        for(auto& ch : t) freq[ch]--;
        int res = 0;
        for(auto& [_, v] : freq) res += abs(v);
        return res / 2;
    }
};