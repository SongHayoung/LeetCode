class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if (n < 4) return {};
        int total = n * (n - 1);
        vector<vector<int>> rem(n, vector<int>(n, 0));
        vector<int> homeRem(n, n - 1), awayRem(n, n - 1), lastSide(n, -1), run(n, 0);
        for (int u = 0; u < n; ++u) for (int v = 0; v < n; ++v) if (u != v) rem[u][v] = 1;
        int prevA = -1, prevB = -1;
        vector<int> H, A; H.reserve(total); A.reserve(total);

        auto okTeam = [&](int u, int side){ return !(lastSide[u] == side && run[u] >= 3); };

        for (int d = 0; d < total; ++d) {
            int bu = -1, bv = -1, best = -1;
            for (int u = 0; u < n; ++u) {
                if (u == prevA || u == prevB || homeRem[u] == 0 || !okTeam(u, 0)) continue;
                for (int v = 0; v < n; ++v) {
                    if (v == u || v == prevA || v == prevB || awayRem[v] == 0 || !okTeam(v, 1)) continue;
                    if (!rem[u][v]) continue;
                    int score = (homeRem[u] << 16) ^ awayRem[v];
                    if (score > best) { best = score; bu = u; bv = v; }
                }
            }
            if (bu == -1) return {};
            rem[bu][bv] = 0; homeRem[bu]--; awayRem[bv]--;
            if (lastSide[bu] == 0) run[bu]++; else { lastSide[bu] = 0; run[bu] = 1; }
            if (lastSide[bv] == 1) run[bv]++; else { lastSide[bv] = 1; run[bv] = 1; }
            H.push_back(bu); A.push_back(bv);
            prevA = bu; prevB = bv;
        }
        vector<vector<int>> res;
        for(int i = 0; i < H.size(); i++) {
            res.push_back({H[i],A[i]});
        }
        return res;
    }
};