class Solution {
public:
    int shareCandies(vector<int>& A, int k) {
        unordered_map<int, int> freq;
        for(int i = k; i < A.size(); i++) {
            freq[A[i]]++;
        }
        int res = freq.size();
        for(int i = k; i < A.size(); i++) {
            if(--freq[A[i]] == 0) freq.erase(A[i]);
            freq[A[i-k]]++;
            res = max(res, (int)freq.size());
        }
        return res;
    }
};