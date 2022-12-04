
#define all(a) begin(a), end(a)

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& A) {
        if(A.size() == 1) return 0;
        long lsum = 0, rsum = accumulate(all(A),0l), n = A.size(), mi = LONG_MAX, res = -1;
        for(int l = 0, r = n - 1; l < n - 1; l++,r--) {
            lsum += A[l];
            rsum -= A[l];

            long lavg = lsum / (l + 1);
            long ravg = rsum / (n - l - 1);
            long diff = abs(lavg - ravg);
            if(diff < mi) {
                mi = diff;
                res = l;
            }
        }
        lsum = accumulate(all(A),0l) / n;
        if(lsum < mi) return n - 1;
        return res;
    }
};
