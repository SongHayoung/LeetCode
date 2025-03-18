class Solution {
public:
    int longestNiceSubarray(vector<int>& A) {
        vector<int> freq(32);
        int res = 0, l = 0, r = 0, n = A.size();
        while(r < n) {
            while(r < n and *max_element(begin(freq), end(freq)) <= 1) {
                res = max(res, r - l);
                for(int i = 0; i < 32; i++) {
                    if(A[r] & (1<<i)) freq[i]++;
                }
                r++;
            }
            if(*max_element(begin(freq), end(freq)) <= 1) res = max(res, r - l);
            while(r < n and *max_element(begin(freq),end(freq)) > 1) {
                for(int i = 0; i < 32; i++) {
                    if(A[l] & (1<<i)) freq[i]--;
                }
                l++;
            }
        }
        return res;
    }
};

