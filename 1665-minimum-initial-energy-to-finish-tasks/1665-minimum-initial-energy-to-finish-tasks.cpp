class Solution {
public:
    int minimumEffort(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto& a, auto& b) {
            int x = a[1] - a[0], y = b[1] - b[0];
            if(x == y) return a[1] > b[1];
            return x > y;
        });
        int res = 0, rem = 0;
        for(auto& a : A) {
            int use = a[0], req = a[1];
            if(rem < req) {
                res += (req - rem);
                rem = req - use;
            } else rem = rem - use;
        }
        return res;
    }
};