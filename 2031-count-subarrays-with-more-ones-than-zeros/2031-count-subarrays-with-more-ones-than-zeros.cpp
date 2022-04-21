class Solution {
    int fenwick[200003];
    void update(int n) {
        while(n < 200003) {
            fenwick[n] += 1;
            n += n & -n;
        }
    }
    int query(int n) {
        int res = 0;
        while(n > 0) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int sum = 100001, mod = 1e9 + 7, res = 0;
        update(sum);
        for(auto& n : nums) {
            sum += (n ? 1 : -1);
            res = (res + query(sum - 1)) % mod;
            update(sum);
        }
        
        return res;
    }
};