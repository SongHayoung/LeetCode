class Solution {
    unordered_map<bitset<28>, pair<int, int>> dp;
    pair<int, int> helper(bitset<28> mask, int& f, int& s, int round, int& n) {
        if(dp.count(mask)) return dp[mask];
        dp[mask] = {INT_MAX, INT_MIN};
        int l = 0, r = n;
        unordered_set<bitset<28>> comb{bitset<28>(0)};
        while(l <= r) {
            while(!mask[l]) l++;
            while(!mask[r]) r--;
            if(l > r) break;
            unordered_set<bitset<28>> ncomb;
            if(l == r) {
                for(bitset<28> c : comb) {
                    c[l] = 1;
                    ncomb.insert(c);
                }
                swap(comb, ncomb);
                break;
            }
            if(l == f and r == s) {
                return dp[mask] = {round, round};
            }
            for(bitset<28> c : comb) {
                if(l == f or l == s or r == f or r== s) {
                    if(l == f or l == s) {
                        c[l] = 1;
                        ncomb.insert(c);
                    } else {
                        c[r] = 1;
                        ncomb.insert(c);
                    }
                } else {
                    c[l] = 1;
                    ncomb.insert(c);
                    c[l] = 0; c[r] = 1;
                    ncomb.insert(c);
                }
            }
            swap(comb, ncomb);
            l++, r--;
        }

        for(auto& c : comb) {
            auto [mi, ma] = helper(c, f, s, round + 1, n);
            dp[mask].first = min(dp[mask].first, mi);
            dp[mask].second = max(dp[mask].second, ma);
        }


        return dp[mask];
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        bitset<28> bi;
        for(int i = 0; i < n; i++) bi[i] = 1;
        --firstPlayer; --secondPlayer;
        auto [mi, ma] = helper(bi, firstPlayer, secondPlayer, 1, n);
        return {mi, ma};
    }
};