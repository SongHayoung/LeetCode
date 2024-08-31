
class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        vector<char> sums(n/k);
        for(int i = 0; i < n; i++) sums[i/k] = (sums[i/k] + s[i] - 'a') % 26;
        string res = "";
        for(int i = 0; i < n / k; i++) res.push_back(sums[i] % 26 + 'a');
        return res;
    }
};