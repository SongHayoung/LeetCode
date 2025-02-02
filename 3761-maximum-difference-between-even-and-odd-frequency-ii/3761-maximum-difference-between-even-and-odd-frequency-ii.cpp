
class Solution {
public:
    int maxDifference(string s, int k) {
        k = max(k,3);
        long long res = INT_MIN, n = s.length();
        for(int a = 0; a < 5; a++) {
            for(int b = 0; b < 5; b++) {
                if(a == b) continue;
                int prea = 0, preb = 0;
                deque<array<long long,3>> dq{{0,0,0}};
                vector<long long> parity(4, INT_MAX);
                for(int i = 0; i < n; i++) {
                    int x = s[i] - '0';
                    if(x == a) prea++;
                    else if(x == b) preb++;
                    dq.push_back({((prea & 1)<<1) | (preb & 1), prea, preb});

                    if(dq.size() > k and (dq[0][1] != prea and dq[0][2] != preb) and prea and preb) {
                        auto [p,pa, pb] = dq.front(); dq.pop_front();
                        parity[p] = min(parity[p], pa - pb);
                    }
                    if(i + 1 >= k and prea and preb) {
                        res = max(res, prea - preb - parity[(((prea & 1)<<1) | (preb & 1))^2]);
                    }
                }
            }
        }
        return res;
    }
};
