class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int less = 0, res = 0, mid = 0, over = 0, mod = 1e9 + 7;
        for(auto& n : nums) {
            if(n < a) less++;
            else if(n > b) over++;
            else mid++;
        }
        auto work = [&](int limit, vector<int>& A) {
            int res = 0;
            for(int i = 0, cnt = 0; i < A.size(); i++) {
                if(A[i] >= limit) continue;
                res = (res + i - cnt) % mod;
                cnt++;
            }
            return res;
        };
        res = work(a,nums);
        vector<int> A;
        for(auto& n : nums) if(n >= a) A.push_back(n);
        res = (res + work(b+1,A)) % mod;
        return res;
    }
};
