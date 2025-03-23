class Solution {
    long long helper(vector<int>& A) {
        long long l = 1, r = 4, cnt = 1, res = 0;
        vector<long long> freq(16);
        while(l <= A[1]) {
            freq[cnt++] = max(0ll, min(r - 1, A[1] * 1ll) - max(l, A[0] * 1ll) + 1);
            l<<=2, r<<=2;
        }
        while(freq.size() > 1) {
            if(freq.back() == 0) freq.pop_back();
            else {
                if(freq.back() >= 2) {
                    res += freq.back() / 2;
                    freq[freq.size()-2] += freq.back() / 2 * 2;
                    freq.back() &= 1;
                }
                if(freq.back()) {
                    res += 1;
                    freq[freq.size()-2] += 1;
                    freq.pop_back();
                    if(freq.size() >= 2) freq[freq.size()-2]++, freq.back() -= 1;
                }
            }
        }
        return res;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for(auto& q : queries) res += helper(q);
        return res;
    }
};