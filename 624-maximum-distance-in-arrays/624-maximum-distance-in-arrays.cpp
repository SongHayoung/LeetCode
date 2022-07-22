class Solution {
public:
    int maxDistance(vector<vector<int>>& A) {
        priority_queue<pair<int, int>> mi;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ma;
        for(int i = 0; i < A.size(); i++) {
            mi.push({A[i][0], i});
            ma.push({A[i].back(), i});
            if(mi.size() > 2) mi.pop();
            if(ma.size() > 2) ma.pop();
        }
        int res = 0;
        auto [ma1, idx1] = ma.top(); ma.pop();
        auto [ma2, idx2] = ma.top();
        auto [mi1, iidx1] = mi.top(); mi.pop();
        auto [mi2, iidx2] = mi.top();
        if(idx1 != iidx1) res = max(res, abs(ma1-mi1));
        if(idx1 != iidx2) res = max(res, abs(ma1-mi2));
        if(idx2 != iidx1) res = max(res, abs(ma2-mi1));
        if(idx2 != iidx2) res = max(res, abs(ma2-mi2));
        return res;
    }
};