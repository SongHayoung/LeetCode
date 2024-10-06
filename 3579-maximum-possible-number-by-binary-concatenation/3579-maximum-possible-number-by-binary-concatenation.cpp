class Solution {
    int build(vector<int>& A) {
        int res = 0;
        for(auto& x : A) {
            int shift = 32 - __builtin_clz(x);
            res = res<<shift | x;
        }
        return res;
    }
public:
    int maxGoodNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int res = 0;
        do {
            res = max(res, build(nums));
        }while(next_permutation(begin(nums), end(nums)));
        return res;
    }
};

