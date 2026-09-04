class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long res = 0, prv = 0, pre = 0;
        for(auto& n : nums) {
            if(n + pre < prv) {
                int diff = prv - (n + pre);
                pre += diff;
                res += diff;
            }
            prv = n + pre;
        }
        return res;
    }
};