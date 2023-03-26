
class Solution {
    int sieve[1010];
    vector<int> prime() {
        vector<int> res;
        for(int i = 2; i < 1000; i++) {
            if(sieve[i]) continue;
            res.push_back(i);
            for(int j = i * i; j < 1000; j += i) {
                sieve[j] = true;
            }
        }
        return res;
    }
public:
    bool primeSubOperation(vector<int>& A) {
        vector<int> p = prime();
        int last = -1000;
        for(int i = 0; i < A.size(); i++) {
            auto pos = lower_bound(begin(p), end(p), A[i]) - begin(p) - 1;
            while(pos >= 0 and A[i] - p[pos] <= last) pos -= 1;
            if(pos == -1 and A[i] <= last) return false;
            last = A[i] - (pos >= 0 ? p[pos] : 0);
        }
        return true;
    }
};

