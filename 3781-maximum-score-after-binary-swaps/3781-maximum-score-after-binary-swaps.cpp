
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int> notSelected;
        long long res = 0;
        for(int i = 0; i < nums.size(); i++) {
            notSelected.push(nums[i]);
            if(s[i] == '1') {
                res += notSelected.top(); notSelected.pop();
            }
        }
        return res;
    }
};

