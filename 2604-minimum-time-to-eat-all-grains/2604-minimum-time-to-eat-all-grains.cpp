class Solution {
    bool helper(vector<int>& A, vector<int>& B, int m) {
        int j = 0;
        for(int i = 0; i < A.size() and j < B.size(); i++) {
            if(A[i] > B[j]) {
                if(A[i] - B[j] > m) return false;
                int move = max({m - 2 * (A[i] - B[j]), 0, (m - (A[i] - B[j])) / 2});
                while(j < B.size() and B[j] <= A[i] + move) j++;
            } else {
                while(j < B.size() and B[j] <= A[i] + m) j++;
            }
        }
        return j == B.size();
    }
public:
    int minimumTime(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        long long l = 0, r = max(abs(A.front() - B.back()), abs(A.back() - B.front())) * 4ll, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(A,B,m);
            if(ok) {
                res = min(res, m);
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};
