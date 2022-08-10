class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& A) {
        int res = INT_MIN;
        unordered_map<int, int> mp;
        for(auto& a : A) {
            mp[a[0]] = max(mp[a[0]], a[2]);
            res = max(res, a[2]);
        }
        vector<pair<int, int>> B;
        for(auto& [k, v]: mp) {
            B.push_back({k,v});
        }
        sort(begin(B), end(B));
        for(int i = B.size()-1, ma = INT_MIN; i >= 0; i--) {
            B[i].second = ma = max(ma, B[i].second);
        }
        for(int i = 0; i < A.size(); i++) {
            int time = A[i][1], v = A[i][2];
            auto lb = lower_bound(begin(B), end(B), pair<int,int>(time + 1, INT_MIN));
            if(lb != end(B)) {
                auto p = lb - begin(B);
                res = max(res, v + B[p].second);
            }
        }
        
        
        return res;
    }
};