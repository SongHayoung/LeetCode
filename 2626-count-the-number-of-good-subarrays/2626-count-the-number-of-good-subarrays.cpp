class Solution {
public:
    long long countGood(vector<int>& A, int k) {
        long long res = 0, l = 0, r = 0, n = A.size(), now = 0;
        unordered_map<long long, long long> freq;
        for(; r < n; r++) {
            now += freq[A[r]];
            freq[A[r]] += 1;
            if(now >= k) {
                while(l < r) {
                    long long cut = freq[A[l]] - 1;
                    if(now - cut >= k) {
                        now -= cut;
                        freq[A[l]] -= 1;
                        l += 1;
                    } else break;
                }
                res += l + 1;
            }
        }
        
        return res;
    }
};