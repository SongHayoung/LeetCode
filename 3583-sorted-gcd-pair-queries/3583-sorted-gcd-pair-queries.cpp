class Solution {
    vector<long long> init(int n) {
        vector<long long> mu(n + 1, 1);
        vector<bool> prime(n + 1, true);
        for(long long i = 2; i <= n; i++) {
            if(!prime[i]) continue;
            for(long long j = i; j <= n; j += i) {
                mu[j] = -mu[j];
                prime[j] = 0;
            }
            for(long long j = i * i; j <= n; j += i * i) mu[j] = 0;
        }
        return mu;
    }
    vector<long long> gcdPairs(vector<int>& A) {
        int n = A.size(), ma = *max_element(begin(A), end(A));
        vector<long long> cnt(ma + 1), freq(ma + 1), mu = init(ma);
        for(auto& x : A) freq[x]++;
        
        for(long long i = 1; i <= ma; i++) {
            long long c = 0;
            for(long long j = i; j <= ma; j += i) c += freq[j];
            
            cnt[i] = c * (c - 1) / 2;
        }
        
        vector<long long> res(ma + 1);
        for(long long i = 1; i <= ma; i++) {
            for(long long j = i; j <= ma; j += i) res[i] += mu[j / i] * cnt[j];
        }
        return res;
    }
    int query(vector<long long>& A, long long x) {
        long long l = 0, r = A.size() - 1, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = A[m] > x;
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<long long> cnt = gcdPairs(nums);
        for(int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i-1];
        vector<int> res;
        for(auto& q : queries) {
            res.push_back(query(cnt,q));
        }
        return res;
    }
};