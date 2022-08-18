class Solution {
public:
    int getWinner(vector<int>& A, int k) {
        int win = 0, winner = 0, appo = 1, n = A.size();
        k = min(k, (int)A.size() - 1);
        while(win < k) {
            if(A[winner] > A[appo]) win++;
            else {
                win = 1;
                winner = appo;
            }
            appo = (appo + 1) % n;
        }
        
        return A[winner];
    }
};