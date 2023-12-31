class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(auto& x : nums) {
            if(x % 2 == 0) cnt += 1;
        }
        return cnt >= 2;
    }
};
