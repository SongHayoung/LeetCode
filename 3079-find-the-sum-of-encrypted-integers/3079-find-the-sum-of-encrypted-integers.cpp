class Solution {
    int helper(int n) {
        int best = 0, cnt = 0;
        while(n) {
            best = max(best, n % 10);
            cnt += 1;
            n /= 10;
        }
        int res = 0;
        for(int i = 0; i < cnt; i++) {
            res += best;
            best *= 10;
        }
        return res;
    }
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int res = 0;
        for(auto& n : nums) res += helper(n);
        return res;
    }
};