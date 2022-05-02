class Solution {
public:
    int minimumEffort(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](vector<int>&a, vector<int>& b) {
           int ad = a[1] - a[0], bd = b[1] - b[0];
            if(ad == bd)
                return a[1] > b[1];
            return ad > bd;
        });
        
        int res = 0, cur = 0;
        for(auto& t : A) {
            int req = t[1], use = t[0];
            
            if(cur < req) {
                res += (req - cur);
                cur = req - use;
            } else {
                cur = cur - use;
            }
        }
        return res;
    }
};