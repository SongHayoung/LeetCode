class Solution {
    bool bit(int x, int n) {
        return (x>>n) & 1;
    }
    bool ok(vector<int>& A, int ma) {
        return *max_element(begin(A), end(A)) <= ma;
    }
    bool helper(vector<pair<int,int>>& A, int pos, vector<int>& now, vector<int>& res) {
        if(res.size() and ok(now, res.size() / 2)) {
            return true;
        }
        if(pos == A.size()) return false;
        if(helper(A,pos+1,now,res)) return true;
        res.push_back(A[pos].second);
        for(int i = 0; i < now.size(); i++) {
            if(bit(A[pos].first, i)) now[i] += 1;
        }
        if(helper(A,pos+1,now,res)) return true;
        for(int i = 0; i < now.size(); i++) {
            if(bit(A[pos].first, i)) now[i] -= 1;
        }
        res.pop_back();
        return false;
    }
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            int mask = 0;
            for(int j = 0; j < m; j++) {
                if(A[i][j]) mask |= 1ll<<j;
            }
            mp[mask] = i;
        }
        vector<pair<int,int>> S;
        for(auto& [k,v]: mp) {
            S.push_back({k,v});
        }
        vector<int> res, now(m);
        helper(S,0,now,res);
        sort(begin(res), end(res));
        return res;
    }
};