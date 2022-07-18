class Solution {
    int helper(vector<string>& A, int k, int cut) {
        vector<pair<string, int>> B;
        for(int i = 0; i < A.size(); i++) {
            B.push_back({A[i].substr(A[i].length() - cut), i});
        }
        sort(begin(B), end(B));
        return B[k-1].second;
    }
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& q : queries) {
            res.push_back(helper(nums, q[0], q[1]));
        }
        return res;
    }
};