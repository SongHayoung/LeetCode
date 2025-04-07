class Solution {
public:
    int minimumPairRemoval(vector<int>& A) {
        vector<long long> nums(begin(A), end(A));
        int n = nums.size(), res = 0, wait = 0;
        vector<int> prv(n), nxt(n);
        for(int i = 0; i < n; i++) {
            prv[i] = i - 1, nxt[i] = i + 1;
        }
        set<pair<long long, long long>> st;
        auto valid = [&](long long idx) {
            if(idx < 0 or idx >= n) return false;
            return nxt[idx] < n;
        };
        auto bad = [&](long long idx) {
            if(!valid(idx)) return false;
            return nums[idx] > nums[nxt[idx]];
        };
        auto apply = [&](long long idx) {
            if(!valid(idx)) return;
            st.insert({nums[idx] + nums[nxt[idx]], idx});
            if(bad(idx)) wait++;
        };
        auto remove = [&](long long idx) {
            if(!valid(idx)) return;
            st.erase({nums[idx] + nums[nxt[idx]], idx});
            if(bad(idx)) wait--;
        };
        auto merge = [&](long long idx) {
            nums[idx] += nums[nxt[idx]];
            nxt[idx] = nxt[nxt[idx]];
            if(nxt[idx] != n) prv[nxt[idx]] = idx;
        };
        for(int i = 0; i < n; i++) apply(i);
        while(wait) {
            int idx = begin(st)->second;
            res++;
            remove(idx);
            remove(nxt[idx]);
            remove(prv[idx]);

            merge(idx);

            apply(idx);
            apply(prv[idx]);
        }

        return res;
    }
};