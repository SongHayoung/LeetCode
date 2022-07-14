class Solution {
public:
    int bestRotation(vector<int>& A) {
        unordered_map<int, int> freq;
        int n = A.size(), res = 0, score = 0, ma = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] > i) continue;
            freq[i-A[i]]++;
            score++;
        }
        ma = score;
        for(int i = 0, j = 1; i < n; i++, j++) {
            score -= freq[j-1];
            if(A[i] > n - 1) continue;
            freq[j+n-1-A[i]]++;
            score++;
            if(ma < score) {
                ma = score;
                res = j;
            }
        }
        
        return res;
    }
};