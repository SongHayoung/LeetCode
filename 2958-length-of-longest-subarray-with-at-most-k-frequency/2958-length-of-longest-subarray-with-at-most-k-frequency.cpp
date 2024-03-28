class Solution {
public:
    int maxSubarrayLength(vector<int>& A, int k) {
        unordered_map<int, int> freq;
        int res = 0, l = 0, r = 0, n = A.size();
        while(r < n) {
            while(r < n) {
                freq[A[r]] += 1;
                int cnt = freq[A[r]];
                r += 1;
                if(cnt > k) break;
                res = max(res, r - l);
            }
            while(freq[A[r-1]] > k) {
                --freq[A[l++]];
            }
        }
        return res;
    }
};