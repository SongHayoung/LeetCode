class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        unordered_set<int> us(begin(nums), end(nums));
        int res = 0;
        for(int i = 1; i <= 2e5; i++) {
            int gcd = 0;
            for(int j = i; j <= 2e5; j += i) {
                if(us.count(j)) gcd = __gcd(gcd,j);
                if(gcd == i) {
                    res++; break;
                }
            }
        }
        return res;
    }
};