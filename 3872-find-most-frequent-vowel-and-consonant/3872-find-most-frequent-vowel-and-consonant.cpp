class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> freq[2];
        unordered_set<char> vowels{'a','e','i','o','u'};
        for(auto& ch : s) freq[vowels.count(ch)][ch]++;
        int ma[2]{0,0};
        for(int i = 0; i < 2; i++) {
            for(auto& [_,v] : freq[i]) ma[i] = max(ma[i], v);
        }
        return ma[0] + ma[1];
    }
};