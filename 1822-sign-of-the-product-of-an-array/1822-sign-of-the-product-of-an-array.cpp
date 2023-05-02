class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for(int n :nums) {
            if(n == 0) return 0;
            else if(n < 0) res = -res;
        }
        return res;
    }
};