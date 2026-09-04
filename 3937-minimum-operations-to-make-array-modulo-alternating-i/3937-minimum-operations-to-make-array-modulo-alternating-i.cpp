
class Solution {
    vector<pair<long long,long long>> helper(vector<int>& A, int k) {
        unordered_set<int> us;
        unordered_map<int,int> freq;
        for(auto& n : A) us.insert(n%k), us.insert((n - 1 + k) % k), us.insert((n + 1) % k), freq[n%k]++;
        vector<pair<long long,long long>> res{{INT_MAX,INT_MAX},{INT_MAX,INT_MAX}};
        
        for(auto& u : us) {
            int cost = 0;
            for(auto& [K,v] : freq) {
                int c = abs(K-u);
                c = min(c, (k - c) % k);
                cost += v * c;
                if(cost >= res.back().first) break;
            }
            res.push_back({cost,u});
            sort(begin(res), end(res));
            res.pop_back();
        }
        return res;
    }
public:
    int minOperations(vector<int>& nums, int k) {
        long long res = INT_MAX, n = nums.size();
        if(n == 1) return 0;
        vector<int> vals[2];
        for(int i = 0; i < nums.size(); i++) vals[i&1].push_back(nums[i]%k);
        auto a = helper(vals[0], k), b = helper(vals[1], k);
        for(auto& [k1,v1] : a) for(auto& [k2,v2] : b) if(v1 != v2) res = min(res, k1 + k2);
        return res;
    }
};