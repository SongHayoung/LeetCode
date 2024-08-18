
class Solution {
    long long helper(vector<vector<pair<long long, long long>>>& A, long long n) {
        vector<long long> dp1(n, -1e18), dp2(n, -1e18);
        long long res = -1e18;
        for(int i = 0; i < A.size(); i++) {
            for(auto& [val1, idx1] : A[i]) res = max(res, val1 + dp2[idx1]);
            for(auto& [val1, idx1] : A[i]) {
                vector<pair<long long, long long>> best;
                for(int j = 0; j < n; j++) {
                    if(j == idx1) continue;
                    best.push_back({dp1[j] + val1, j});
                    sort(rbegin(best), rend(best));
                    if(best.size() > 3) best.pop_back();
                }
                for(int j = 0; j < n; j++) {
                    if(j == idx1) continue;
                    for(auto& [val2,idx2] : best) {
                        if(j == idx2) continue;
                        dp2[j] = max(dp2[j], val2);
                        break;
                    }
                }

            }
            for(auto& [val1, idx1] : A[i]) dp1[idx1] = max(dp1[idx1], val1);
        }
        return res;
    }
public:
    long long maximumValueSum(vector<vector<int>>& A) {
        long long n = A.size(), m = A[0].size();
        vector<vector<pair<long long,long long>>> tp3(m);
        auto udt = [&](long long i, long long j, long long val) {
            tp3[j].push_back({val,i});
            sort(rbegin(tp3[j]), rend(tp3[j]));
            while(tp3[j].size() > 3) tp3[j].pop_back();
        };
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) udt(i,j,A[i][j]);
        return helper(tp3, n);
    }
};

