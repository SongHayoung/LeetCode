class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long ma1 = LLONG_MIN, ma2 = LLONG_MIN, ma3 = LLONG_MIN;
        for(auto& x : nums) {
            if(x <= ma3) continue;
            if(ma1 < x) {
                ma3 = ma2;
                ma2 = ma1;
                ma1 = x;
            } else if(ma1 > x) {
                if(ma2 < x) {
                    ma3 = ma2;
                    ma2 = x;
                } else if(ma2 > x) {
                    if(ma3 < x) ma3 = x;
                }
            }
        }
        return ma3 == LLONG_MIN ? ma1 : ma3;
    }
};