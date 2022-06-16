class Solution {
    int leftOf(vector<int>& A, int now) {
        while(now and A[now] == A[now - 1]) now--;
        if(now == 0) return -1;
        if(A[now] < A[now - 1]) return -1;
        int res = now;
        while(now and A[now] >= A[now - 1]) {
            if(A[now] > A[now - 1]) res = now - 1;
            now--;
        }
        return res;
    }
    int rightOf(vector<int>& A, int now) {
        while(now != A.size() - 1 and A[now] == A[now + 1]) now++;
        if(now == A.size() - 1) return -1;
        if(A[now] < A[now + 1]) return -1;
        int res = now;
        while(now != A.size() - 1 and A[now] >= A[now + 1]) {
            if(A[now] > A[now + 1]) res = now + 1;
            now++;
        }
        return res;
    }
public:
    vector<int> pourWater(vector<int>& A, int volume, int k) {
        while(volume--) {
            int l = leftOf(A, k);
            if(l != -1) {
                A[l]++;
            } else {
                int r = rightOf(A, k);
                if(r != -1) {
                    A[r]++;
                } else A[k]++;
            }
        }
        return A;
    }
};