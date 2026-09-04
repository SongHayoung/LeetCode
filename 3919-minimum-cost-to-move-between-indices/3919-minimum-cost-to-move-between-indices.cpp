class Solution {
    vector<int> helper(vector<int>& A, bool fl) {
        vector<int> res(A.size() + 1);
        res[1] = 1;
        for(int i = 1; i < A.size() - 1; i++) {
            int le = abs(A[i] - A[i-1]), ri = abs(A[i+1] - A[i]);
            if((ri < le)) res[i+1] = res[i] + 1;
            else if(le == ri and !fl) res[i+1] = res[i] + 1;
            else res[i+1] = res[i] + ri;
        }
        return res;
    }
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre = helper(nums,1);
        reverse(begin(nums), end(nums));
        vector<int> suf = helper(nums,0);
        vector<int> res;
        for(auto& q : queries) {
            int l = q[0] ,r = q[1];
            if(l == r) res.push_back(0);
            else if(l < r) res.push_back(pre[r] - pre[l]);
            else res.push_back(suf[n-r-1] - suf[n-l-1]);
        }
        return res;
    }
};
