class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < nums.size(); i++) {
            int aa = a + (nums[i] != 1);
            int bb = min(a,b) + (nums[i] != 2);
            int cc = min({a,b,c}) + (nums[i] != 3);
            a = aa, b = bb, c = cc;
        }
        return min({a,b,c});
    }
};