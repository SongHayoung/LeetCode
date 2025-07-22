class Solution {
public:
    int maximumUniqueSubarray(vector<int>& A) {
        int res = 0, l = 0, r = 0, n = A.size(), sum = 0;;
        unordered_map<int, int> freq;
        while(r < n) {
            while(r < n and freq[A[r]] == 0) {
                freq[A[r]]++;
                sum += A[r++];
                res = max(res, sum);
            }
            while(r < n and freq[A[r]] == 1) {
                freq[A[l]]--;
                sum -= A[l++];
            }
            
        }
        return res;
    }
};