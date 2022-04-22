class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int startPos, int k) {
        int st = startPos - k;
        int l = 0, r = 0, n = f.size(), res = 0, sum = 0;
        while(l < n and f[l][0] < st) l++;
        r = l;
        while(l < n and r < n and f[r][0] <= startPos + k) {
            sum += f[r][1];
            while(k < min(startPos - 2 * f[l][0] + f[r][0], 2 * f[r][0] - f[l][0] - startPos))
                sum -= f[l++][1];
            
            res = max(res, sum);
            r++;
        }
        
        return res;
    }
};