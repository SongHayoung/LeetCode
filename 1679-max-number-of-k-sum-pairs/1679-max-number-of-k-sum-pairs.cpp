class Solution {
public:
    int maxOperations(vector<int>& A, int n) {
        int res = 0;
        unordered_map<int,int> mp;
        for(auto& a : A) mp[a]++;
        for(auto& [k, v] : mp) {
            if(n - k == k) {
                res += v / 2;
                v -= v / 2;
            } else if(mp.count(n-k)) {
                int mi = min(v, mp[n - k]);
                res += mi;
                mp[n-k] -= mi;
                v -= mi;
            }
        }
        
        return res;
    }
};