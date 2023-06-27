class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, vector<vector<int>>> m;
        int cnt(0);
        for(auto& n1 : nums1) {
            for(auto& n2 : nums2) {
                int sum = n1 + n2;
                if(cnt < k) {
                    m[sum].push_back({n1, n2});
                    cnt++;
                } else if(prev(m.end())->first > sum) {
                    m[sum].push_back({n1, n2});
                    prev(m.end())->second.pop_back();
                    if(prev(m.end())->second.empty()) {
                        m.erase(prev(m.end()));
                    }
                } else break;
            }
        }
        vector<vector<int>> res;
        for(auto e : m) {
            res.insert(res.end(), e.second.begin(), e.second.end());
        }
        return res;
    }
};