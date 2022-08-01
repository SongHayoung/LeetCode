class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        int vis[111][111] = {};
        vector<string> res;
        for(int den = 2; den <= n; den++) {
            for(int num = 1; num < den; num++) {
                int gcd = __gcd(den, num);
                if(vis[num/gcd][den/gcd]) continue;
                vis[num/gcd][den/gcd] = true;
                res.push_back(to_string(num) + "/" + to_string(den));
            }
        }
        return res;
    }
};