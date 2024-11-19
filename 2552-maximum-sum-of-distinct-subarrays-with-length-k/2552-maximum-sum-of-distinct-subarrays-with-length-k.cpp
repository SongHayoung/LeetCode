class Solution {
public:
    long long maximumSubarraySum(vector<int>& A, int k) {
        long long res = 0, sum = 0;
        unordered_map<long long, long long> freq;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            freq[A[i]]++;
            if(i >= k) {
                if(--freq[A[i-k]] == 0) freq.erase(A[i-k]);
                sum -= A[i-k];
            }
            if(freq.size() == k) res = max(res, sum);
        }
        return res;
    }
};