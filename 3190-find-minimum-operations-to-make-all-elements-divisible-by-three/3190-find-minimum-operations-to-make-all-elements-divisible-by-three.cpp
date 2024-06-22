class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(auto& x : nums) {
            if(x % 3) res++;
        }
        return res;
    }
};
