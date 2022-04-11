class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        m[0].push_back(0);
        int n = 1, sum = 0, res = 0;
        for(auto& num : nums) {
            sum += num;
            m[sum].push_back(n++);
        }
        set<int> s;
        for(auto& entity : m) {
            entity.second.begin();
            if(m.count(entity.first - k)) {
                for(auto pos = upper_bound(entity.second.begin(), entity.second.end(), m[entity.first - k][0]); pos != end(entity.second); pos++) {
                    res += (lower_bound(m[entity.first - k].begin(), m[entity.first - k].end(), *pos) - m[entity.first-k].begin());
                }
            }
        }

        return res;
    }
};
