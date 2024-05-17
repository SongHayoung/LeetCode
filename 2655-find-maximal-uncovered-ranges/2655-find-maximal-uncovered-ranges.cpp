class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& A) {
        A.push_back({n,n});
        A.push_back({-1,-1});
        sort(rbegin(A),rend(A));
        vector<vector<int>> res;
        while(A.size()) {
            int x = A.back()[1];
            while(A.size() and A.back()[0] <= x + 1) {
                x = max(x, A.back()[1]); A.pop_back();
            }
            if(A.size()) {
                res.push_back({x+1,A.back()[0]-1});
            }
        }
        return res;
    }
};