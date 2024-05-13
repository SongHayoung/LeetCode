class Solution {
public:
    long long minimumRemoval(vector<int>& A) {
        long long sum = accumulate(begin(A), end(A), 0ll), res = sum;
        sort(rbegin(A), rend(A));
        long long exc = 0;
        while(A.size()) {
            int x = A.back();
            long long add = 0;
            while(A.size() and A.back() == x) {
                add += x;
                A.pop_back();
                sum -= x;
            }
            res = min(res, (long long)(exc + sum - x * A.size()));
            exc += add;
        }
        return res;
    }
};
