class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mi = 0, ma = 0, sum = 0, res = 0;
        
        for(auto& n : nums) {
            sum += n;
            res = max({res, abs(sum - mi), abs(sum - ma)});
            mi = min(mi, sum);
            ma = max(ma, sum);
        }
        
        return res;
    }
};