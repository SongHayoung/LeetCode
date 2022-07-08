class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& A) {
        queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
        vector<int> res;
        for(auto& row : A) {
            auto now = next(row.begin());
            res.push_back(row[0]);
            int sz = q.size();
            if(now != row.end())
                q.push({now, row.end()});
            while(sz--) {
                auto [it, end] = q.front(); q.pop();
                res.push_back(*it);
                auto iit = next(it);
                if(iit != end) q.push({iit, end});
            }
        }
        while(!q.empty()) {
            auto [it, end] = q.front(); q.pop();
            res.push_back(*it);
            auto iit = next(it);
            if(iit != end) q.push({iit, end});
        }
        return res;
    }
};