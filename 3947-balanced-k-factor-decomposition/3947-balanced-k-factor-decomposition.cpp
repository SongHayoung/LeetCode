
class Solution {
    vector<int> res;
    int best;
    void dfs(vector<int>& A, vector<int>& now, int n, int k, long long val) {
        if(k == 0) {
            if(n == val) {
                int diff = *max_element(begin(now), end(now)) - *min_element(begin(now), end(now));
                if(best > diff) {
                    best = diff, res = now;
                }
            }
            return;
        }
        if(val > n) return;
        for(auto& a : A) {
            now.push_back(a);
            dfs(A,now,n,k-1,val * a);
            now.pop_back();
        }
    }
public:
    vector<int> minDifference(int n, int k) {
        vector<int> divs;
        for(long long i = 1; i * i <= n; i++) {
            if(n % i) continue;
            divs.push_back(i);
            if(i * i != n) divs.push_back(n / i);
        }
        best = INT_MAX;
        vector<int> now;
        dfs(divs,now,n,k,1);
        return res;
    }
};