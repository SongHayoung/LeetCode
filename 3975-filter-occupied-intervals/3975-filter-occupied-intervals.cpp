class Solution {
    vector<vector<int>> merge(vector<vector<int>>& A) {
        vector<vector<int>> res;
        sort(begin(A), end(A));
        for(auto& a : A) {
            if(res.size() and res.back().back() + 1 >= a[0]) {
                res.back().back() = max(res.back().back(), a[1]);
            } else res.push_back(a);
        }
        return res;
    }
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> A = merge(occupiedIntervals);
        vector<vector<int>> res;
        for(auto& a : A) {
            if(a[1] < freeStart or a[0] > freeEnd) res.push_back(a);
            else {
                int l = a[0], r = a[1];
                if(freeStart <= l and l <= freeEnd) l = freeEnd + 1;
                if(freeStart <= r and r <= freeEnd) r = freeStart - 1;
                if(l > r) continue;
                if(l > freeEnd or r < freeStart) res.push_back({l,r});
                else {
                    res.push_back({l,freeStart - 1});
                    res.push_back({freeEnd+1, r});
                }
            }
        }
        return res;
    }
};