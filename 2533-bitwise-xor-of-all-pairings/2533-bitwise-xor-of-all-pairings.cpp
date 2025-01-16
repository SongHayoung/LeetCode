class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
public:
    int xorAllNums(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<int> freq(32);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < 32; j++) {
                if(bit(B[i],j)) freq[j]++;
            }
        }
        vector<int> freq2(32);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 32; j++) {
                if(bit(A[i],j)) {
                    freq2[j] += (m - freq[j]);
                } else freq2[j] += freq[j];
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++) if(freq2[i] & 1) res |= 1<<i;
        return res;
    }
};