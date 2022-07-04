class Solution {
public:
    long long largestEvenSum(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int n = A.size();
        long long res = 0;
        long long miodd = -1, mieven = -1;
        for(int i = n - 1; i >= n - k; i--) {
            res += A[i];
            if(A[i] & 1) miodd = A[i];
            else mieven = A[i];
        }
        if(res & 1) {
            bool reqeven = miodd != -1, reqodd = mieven != -1;
            bool findeven = false, findodd = false;
            int odd = -1, even = -1;
            for(int i = n-k-1; i >= 0; i--) {
                if(A[i] & 1 and reqodd and !findodd) {
                    odd = A[i];
                    findodd = true;
                }
                if(A[i] % 2 == 0 and reqeven and !findeven) {
                    even = A[i];
                    findeven = true;
                }
            }
            long long rres = -1;
            if(reqeven and findeven) {
                rres = max(rres, res - miodd + even);
            }
            if(reqodd and findodd) {
                rres = max(rres, res - mieven + odd);
            }
            return rres;
        } 
        return res;
    }
};