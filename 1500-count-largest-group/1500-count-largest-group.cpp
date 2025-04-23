class Solution {
    int sum(int n) {
        int res = 0;
        while(n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int ma = 0;
        for(int i = 1; i <= n; i++) ma = max(ma, ++mp[sum(i)]);
        int res = 0;
        for(auto& [k,v] : mp) res += v == ma;
        return res;
    }
};