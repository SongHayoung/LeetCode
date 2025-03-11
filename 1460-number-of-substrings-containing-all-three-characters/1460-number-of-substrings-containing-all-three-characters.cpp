class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, n = s.length(), l = 0;
        unordered_map<char, int> freq;

        for(int i = 0; i < n; i++) {
            freq[s[i]]++;

            while(freq[s[l]] > 1) {
                freq[s[l++]]--;
            }

            if(min({freq['a'], freq['b'], freq['c']}) == 1) {
                res += l + 1;
            }
        }
        return res;
    }
};