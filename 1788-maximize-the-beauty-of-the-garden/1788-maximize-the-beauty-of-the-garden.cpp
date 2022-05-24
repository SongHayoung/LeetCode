class Solution {
public:
    int maximumBeauty(vector<int>& A) {
        int n = A.size();
        unordered_map<int, pair<int, int>> mp;
        vector<int> psum(n + 1);
        vector<int> pnegsum(n + 1);
        for(int i = 0; i < n; i++) {
            if(mp.count(A[i])) mp[A[i]].second = i;
            else mp[A[i]] = {i, i};
            psum[i + 1] = psum[i] + A[i];
            if(A[i] < 0) pnegsum[i + 1] = pnegsum[i] + A[i];
            else pnegsum[i + 1] = pnegsum[i];
        }
        
        int res = INT_MIN;
        for(auto& [_, range] : mp) {
            int s = range.first, e = range.second;
            if(s == e) continue;
            res = max(res, psum[e + 1] - psum[s] - (pnegsum[e] - pnegsum[s + 1]));
        }
        return res;
    }
};