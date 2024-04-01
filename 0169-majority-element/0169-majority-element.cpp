class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1, cnt = 0;
        for(auto& x : nums) {
            if(x == res) cnt++;
            else {
                if(--cnt < 0) cnt = 1, res = x;
            }
        }
        return res;
    }
};