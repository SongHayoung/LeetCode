class Solution {
    long long helper(vector<int>& A, int k) {
        long long res = 0;
        for(auto& a : A) {
            res += abs(k - a);
        }
        return res;
    }
public:
    int minMoves2(vector<int>& A) {
        long long res = LLONG_MAX, ma = *max_element(begin(A), end(A)), mi = *min_element(begin(A), end(A));
        while(mi <= ma) {
            int m = mi + (ma - mi) / 2;
            long long diff = helper(A, m);
            long long diff2 = helper(A, m + 1);
            if(diff < diff2) ma = m - 1;
            else mi = m + 1;
            res = min({res, diff, diff2});
        }
        return res;
    }
};