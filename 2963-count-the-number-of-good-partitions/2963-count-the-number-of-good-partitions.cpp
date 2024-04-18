class Solution {
    long long modpow(long long x, long long p) {
        long long mod = 1e9 + 7, res = 1;
        while(p) {
            if(p & 1) res = (res * x) % mod;
            x = x * x % mod;
            p /= 2;
        }
        return res;
    }
public:
    int numberOfGoodPartitions(vector<int>& A) {
        unordered_map<int,pair<int,int>> mp;
        for(int i = 0; i < A.size(); i++) {
            if(!mp.count(A[i])) mp[A[i]] = {i,i};
            mp[A[i]].second = i;
        }
        vector<pair<int, int>> ord;
        for(auto& [_,p] : mp) ord.push_back(p);
        sort(rbegin(ord), rend(ord));
        int po = -1;
        while(ord.size()) {
            int r = ord.back().second;
            while(ord.size() and ord.back().first <= r) {
                r = max(r, ord.back().second);
                ord.pop_back();
            }
            po++;
        }
        return modpow(2,po);
    }
};