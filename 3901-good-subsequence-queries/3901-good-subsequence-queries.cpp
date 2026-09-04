
int __gcd(int x, int y) { return !y ? x : __gcd(y, x % y); }

class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        unordered_map<int,int> freq;
        int dup = 0, tot = 0;
        auto add = [&](int x) {
            tot++;
            if(++freq[x] == 2) dup++;
        };
        auto del = [&](int x) {
            tot--;
            if(--freq[x] == 1) dup--;
            if(freq[x] == 0) freq.erase(x);
        };
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % p) continue;
            add(nums[i] / p);
        }
        auto gcds = [&](int skip = -1) {
            int g = 0;
            for(auto& [k,v] : freq) {
                if(k == skip) continue;
                g = __gcd(g,k);
                if(g == 1) return true;
            }
            return false;
        };
        int res = 0, n = nums.size();
        for(auto& q : queries) {
            int idx = q[0], val = q[1];
            if(nums[idx] % p == 0) del(nums[idx] / p);
            nums[idx] = val;
            if(nums[idx] % p == 0) add(nums[idx] / p);
            if(gcds() == 1) {
                if(tot != n) res++;
                else {
                    if(dup >= 1) res++;
                    else {
                        if(freq.count(1)) res++;
                        else {
                            for(auto& [k,v] : freq) {
                                if(!gcds(k)) continue;
                                res++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};