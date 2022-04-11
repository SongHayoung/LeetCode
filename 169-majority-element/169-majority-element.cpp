class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, res;
        for(auto n : nums) {
            if(count == 0) {
                count = 1;
                res = n;
            } else if(res == n) count++;
            else count--;
        }
        return res;
    }
};