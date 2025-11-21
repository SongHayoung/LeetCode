class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int res = INT_MAX;
        auto qry = [&](vector<int>& A) {
            if(A.size() < 3) return INT_MAX;
            int n = A.size(), res = INT_MAX;
            vector<int> S{A[n-3], A[n-2], A[n-1]};
            do {
                int i = S[0], j = S[1], k = S[2];
                res = min(res, abs(i - j) + abs(i - k) + abs(j - k));
            } while(next_permutation(begin(S), end(S)));
            return res;
        };
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            res = min(res, qry(mp[nums[i]]));
        }
        return res == INT_MAX ? -1 : res;
    }
};