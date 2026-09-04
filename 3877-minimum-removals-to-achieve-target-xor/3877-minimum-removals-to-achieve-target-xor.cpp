class Solution {
    bool on(int a, int i) {
        return ((a>>i)&1);
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        sort(rbegin(nums), rend(nums));
        while(nums.size() and nums.back() == 0) nums.pop_back();
        if(nums.empty()) return !target ? 0 : -1;
        reverse(begin(nums), end(nums));
        unordered_map<int,int> dp{{0,0}};
        for(int i = 30; i >= 0; i--) {
            if(dp.size() == 0) return -1;
            unordered_map<int,int> freq;
            while(nums.size() and on(nums.back(),i)) {
                freq[nums.back()]++;
                nums.pop_back();
            }
            unordered_map<int,int> dpp;
            bool ok = on(target,i);
            unordered_map<int,int> bits[2];
            if(freq.size() == 0) {
                bits[0][0] = 0;
            } else {
                unordered_map<int,int> now{{0,0}};
                for(auto& [k,v] : freq) {
                    int c = v % 2 == 0;
                    unordered_map<int,int> cur;
                    for(auto& [kk,vv] : now) {
                        if(cur.count(kk^k)) cur[kk^k] = min(cur[kk^k], vv + c);
                        else cur[kk^k] = vv + c;

                        if(cur.count(kk)) cur[kk] = min(cur[kk], vv + !c);
                        else cur[kk] = vv + !c;
                    }
                    swap(now,cur);
                }
                for(auto& [k,v] : now) bits[on(k,i)][k] = v;
            }
            unordered_map<int,int> origin[2];
            for(auto& [k,v] : dp) origin[on(k,i)][k] = v;
            int mask = (1<<i) - 1;
            for(int a : {0,1}) for(int b : {0,1}) {
                if((a ^ b) != ok) continue;
                for(auto& [k1,v1] : bits[a]) for(auto& [k2,v2] : origin[b]) {
                    int k = (k1 ^ k2) & mask;
                    if(dpp.count(k)) dpp[k] = min(dpp[k], v1 + v2);
                    else dpp[k] = v1 + v2;
                }
            }
            swap(dp,dpp);
        }
        if(dp.empty()) return -1;
        return dp.begin()->second;
    }
};