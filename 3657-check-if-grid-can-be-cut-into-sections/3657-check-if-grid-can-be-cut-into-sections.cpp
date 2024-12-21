
class Solution {
    bool helper(vector<pair<int,int>>& A) {
        sort(begin(A), end(A));
        vector<pair<int,int>> res;
        for(auto& [l,r] : A) {
            if(res.size() == 0 or res.back().second <= l) {
                res.push_back({l,r});
            } else res.back().second = max(res.back().second, r);
        }

        return res.size() >= 3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> A,B;
        for(auto& r : rectangles) {
            A.push_back({r[0],r[2]});
            B.push_back({r[1],r[3]});
        }
        return helper(A) or helper(B);
    }
};