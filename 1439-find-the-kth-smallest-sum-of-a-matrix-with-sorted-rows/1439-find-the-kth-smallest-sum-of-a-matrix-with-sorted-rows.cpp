class Solution {
    int getCount(vector<vector<int>>& mat, int& mid, int& k, int row = 0, int sum = 0) {
        if(sum > mid) return 0;
        if(row == mat.size()) return 1;
        int res = 0;
        for(auto& num : mat[row]) {
            int ans = getCount(mat, mid, k, row + 1, sum + num);
            if(!ans) break;
            res += ans;
            if(res > k) break;
        }
        return res;
    }
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int l = 0, r = INT_MAX, n = mat.size(), m = mat[0].size();
        while(l <= r) {
            int m = l + (r-l) / 2;
            
            int c = getCount(mat, m, k);
            
            if(c >= k) r = m - 1;
            else l = m + 1;
            
            
        }
        return l;
    }
};