class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> freq;
        for(int i = 0; i < s.length(); i++) freq[s[i]] = i;
        int res = 0;
        for(int i = 0; i < t.length(); i++) {
            res += abs(freq[t[i]] - i);
        }
        return res;
    }
};