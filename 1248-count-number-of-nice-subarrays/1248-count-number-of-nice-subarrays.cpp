class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        int n = A.size(), res = 0;
        deque<int> dq{-1};
        for(int i = 0; i < n; i++) {
            if(A[i] & 1) dq.push_back(i);
            if(dq.size() > k + 1) dq.pop_front();
            if(dq.size() == k + 1) res += dq[1] - dq[0];
        }
        return res;
    }
};