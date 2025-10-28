class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto& n : nums) n = abs(n);
        deque<int> A(begin(nums), end(nums));
        sort(begin(A), end(A));
        long long res = 0, op = 0;
        while(A.size()) {
            if(op) {
                res -= 1ll * A.front() * A.front(); A.pop_front();
            } else {
                res += 1ll * A.back() * A.back(); A.pop_back();
            }
            op = !op;
        }
        return res;
    }
};