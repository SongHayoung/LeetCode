
int factor[101010];
bool fl = false;
void init() {
    if(fl) return;
    for(int i = 2; i < 101010; i++) {
        if(factor[i]) continue;
        for(int j = i; j < 101010; j += i) {
            factor[j] = i;
        }
    }
}
unordered_set<int> get(int x) {
    unordered_set<int> us;
    while(x > 1) {
        int d = factor[x];
        us.insert(d);
        while(x % d == 0) x /= d;
    }
    return us;
}
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int res = -1, l = 0, r = 0, n = nums.size();
        init();
        unordered_map<int,int> mp;
        auto op = [&](unordered_set<int>& us, int o) {
            for(auto& u : us) {
                mp[u] += o;
                if(mp[u] == 0) mp.erase(u);
            }
        };
        while(r < n) {
            auto u = get(nums[r++]);
            op(u,1);
            while(mp.size() > k) {
                auto u = get(nums[l++]);
                op(u,-1);
            }
            res = max(res, r - l);
        }
        return res;
    }
};