class Solution {
    vector<string> res;
    void helper(string& s, int l, int r, unordered_map<char,int>& counter) {
        if(l == r) {
            for(auto& [ch, c] : counter) {
                if(c == 1) {
                    s[l] = ch;
                    res.push_back(s);
                }
            }
        } else if(l > r) {
            res.push_back(s);
        } else {
            for(auto& [ch, c] : counter) {
                if(c >= 2) {
                    s[l] = s[r] = ch;
                    counter[ch] -= 2;
                    helper(s, l + 1, r - 1, counter);
                    counter[ch] += 2;
                }
            }
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char,int> counter;
        for(auto& ch: s) counter[ch]++;
        helper(s, 0, s.length() - 1, counter);
        return res;
    }
};