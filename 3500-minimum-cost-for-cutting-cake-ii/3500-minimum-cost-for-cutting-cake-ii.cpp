class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        long long res = 0, sa = accumulate(begin(A), end(A),0ll), sb = accumulate(begin(B), end(B), 0ll);
        while(A.size() and B.size()) {
            if(A.back() > B.back()) {
                res += A.back() + sb;
                sa -= A.back();
                A.pop_back();
            } else {
                res += B.back() + sa;
                sb -= B.back();
                B.pop_back();
            }
        }
        return res + sa + sb;
    }
};