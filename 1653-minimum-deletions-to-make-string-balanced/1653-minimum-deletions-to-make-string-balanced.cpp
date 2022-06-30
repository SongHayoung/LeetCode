class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length(), res = INT_MAX;
        vector<int> B;
        for(int i = 0, a = 0, b = 0; i < n; i++) {
            if(s[i] == 'b') b++;
            B.push_back(b);
        }
        for(int i = n - 1, a = 0; i >= 0; i--) {
            res = min(res, B[i] + a - (s[i] == 'b'));
            if(s[i] == 'a') a++;
        }
        return res;
    }
};