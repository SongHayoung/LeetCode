
struct MergeInterval {
    map<int,int> range;
    int elem = 0;
    void add(int x) {
        elem++;
        auto it = range.upper_bound(x);
        if(it != begin(range) and prev(it)->second + 1 == x) {
            --it;
        } else {
            range[x] = x;
            it = range.lower_bound(x);
        }
        it->second = max(it->second, x);
        while(next(it) != end(range) and it->second + 1 == next(it)->first) {
            it->second = next(it)->second;
            range.erase(next(it));
        }
    }
};
class Solution {
    long long helper(map<int,vector<int>>& mp) {
        mp[0].push_back(0);
        long long res = 0;
        MergeInterval mi;
        for(auto it = begin(mp); it->first != 0; it++) {
            for(auto& at : it->second) mi.add(at);
            res += mi.range.size() * (next(it)->first - it->first);
        }
        return res;
    }
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long n = nums.size();
        map<int,vector<int>> pos, neg;
        for(int i = 0; i < n; i++) {
            int x = nums[i] - target[i];
            if(x > 0) pos[-x].push_back(i);
            else if(x < 0) neg[x].push_back(i);
        }
        return helper(pos) + helper(neg);
    }
};