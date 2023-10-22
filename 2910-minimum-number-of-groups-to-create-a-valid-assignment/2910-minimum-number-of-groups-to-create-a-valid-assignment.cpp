class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& n : nums) freq[n] += 1;
        unordered_map<int, int> gc;
        int mi = 1e9;
        for(auto& [_,v] : freq) {
            mi = min(mi, v);
            gc[v] += 1;
        }
        auto can = [&](int cnt, int target, bool fl) {
            int d = cnt / target, r = cnt % target;
            if(r == 0) return true;
            if(!fl) return false;
            int x = target - r;
            return d >= x;
        };
        auto sum = [&](int cnt, int target) {
            int d = cnt / target, r = cnt % target;
            if(r == 0) return d;
            return d + 1;
        };
        for(int i = mi; i >= 1; i--) {
            bool ok = true;
            long long now = 0;
            for(auto& [g,cnt] : gc) {
                int gg = g;
                if(can(gg,i+1,true)) {
                    now += cnt * sum(gg,i+1);
                } else if(can(gg,i,false)) {
                    now += cnt * sum(gg,i);
                } else ok = false;
                if(!ok) break;
            }
            if(ok) {
                return now;
            }
        }
        return -1;
    }
};