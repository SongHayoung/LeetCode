class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        deque<int> dq;
        for(int i = A.size() - 1; i >= 0; i--) {
            dq.push_front(A[i]);
            if(dq.size() > k) dq.pop_back();
            int ma = 0;
            for(int j = 0; j < dq.size(); j++) {
                ma = max(ma, dq[j]);
                A[i] = max(A[i], ma * (j + 1) + (i + j + 1 < A.size() ? A[i+j+1] : 0));
            }
        }
        return A[0];
    }
};