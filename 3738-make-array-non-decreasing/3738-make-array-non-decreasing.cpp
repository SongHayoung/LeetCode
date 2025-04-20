class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int res = 0, ma = 0;
        vector<int> st;
        for(auto& n : nums) {
            if(n >= ma) {
                ma = n, res++;
            }
        }
        return res;
    }
};