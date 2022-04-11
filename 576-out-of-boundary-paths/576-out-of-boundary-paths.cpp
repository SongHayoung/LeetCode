class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int MOD = 1e9+7;
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int res = 0;
        vector<map<pair<int,int>, int>> ball(N + 1, map<pair<int,int>, int>());

        ball[N][{i + 1, j + 1}]++;
        for(int move = N; move >= 1; move--) {
            for(auto& pos : ball[move]) {
                auto& p = pos.first;
                for(int i = 0; i < 4; i++) {
                    int ny = p.first + dy[i];
                    int nx = p.second + dx[i];
                    if(0 < nx && nx <= n && 0 < ny && ny <= m) {
                        ball[move - 1][{ny, nx}] = (ball[move - 1][{ny, nx}] + pos.second) % MOD;
                    }
                    if((p.first == 1 || p.first == m || p.second == 1 || p.second == n) && (ny == 0 || nx == 0 || ny == m + 1 || nx == n + 1)) {
                        res = (res + pos.second) % MOD;
                    }
                }
            }
        }
        return res;
    }
};