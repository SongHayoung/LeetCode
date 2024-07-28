class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0, sum = 0;
        for(auto& n : nums) {
            sum += n;
            if(n < 10) sum1 += n;
        }
        return sum != sum1 * 2;
    }
};