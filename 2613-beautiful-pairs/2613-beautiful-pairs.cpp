class Solution {
public:
    vector<int> beautifulPair(vector<int>& A, vector<int>& B) {
        map<int, map<int, int>> mp;
        vector<int> res{INT_MAX, INT_MAX};
        int dist = INT_MAX / 2;
        auto chmin = [&](int i, int j) {
            int now = abs(A[i] - A[j]) + abs(B[i] - B[j]);
            if(dist == now) res = min(res, {min(i,j),max(i,j)});
            else if(dist > now) {
                dist = now;
                res = {min(i,j), max(i,j)};
            }
        };
        for(int i = A.size() - 1; i >= 0; i--) {
            int a = A[i], b = B[i];
            auto lo = mp.lower_bound(a - dist);
            auto hi = mp.upper_bound(a + dist);
            for(auto it = lo; it != hi; it++) {
                auto itt = it->second.lower_bound(b);
                if(itt != end(it->second)) chmin(i,itt->second);
                if(itt != begin(it->second)) chmin(i, prev(itt)->second);
            }

            mp[a][b] = i;
        }
        return res;
    }
};