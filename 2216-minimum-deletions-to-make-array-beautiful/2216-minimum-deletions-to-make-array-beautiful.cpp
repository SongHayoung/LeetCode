class Solution {
public:
    int minDeletion(vector<int>& A) {
        int res = 0, n = A.size();
        for(int i = 0; i < n;) {
            if(i + 1 == n) break;
            if(A[i] == A[i + 1]) {
                int j = i + 1;
                while(j < n and A[j] == A[i]) j++;
                res += j - i - 1;
                i = j + 1;
            } else i += 2;
        }
        if((n - res) & 1) res += 1;
        return res;
    }
};