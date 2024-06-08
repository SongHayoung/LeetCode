class Solution {
public:
    int findWinningPlayer(vector<int>& A, int k) {
        int ma = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[ma] < A[i]) ma = i;
            int j = i + 1;
            while(j < A.size() and A[i] > A[j]) j++;
            int x = j - i - (i == 0);
            if(x >= k) return i;
            i = j - 1;
        }
        return ma;
    }
};