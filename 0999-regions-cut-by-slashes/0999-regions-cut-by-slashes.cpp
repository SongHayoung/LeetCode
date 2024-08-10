class Solution {
    int uf[3600];
    int find(int u) {
        return u == uf[u] ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu, pv);
    }
    array<int, 4> pos(int i, int j, int n) {
        int a = i * n * 4 + j * 4, b = a + 1, c = b + 1, d = c + 1;
        return {a, b, c, d};
    }
    void merge(int y, int x, int n) {
        int dy[4] {-1, 0, 1, 0}, dx[4] {0, 1, 0, -1};
        auto[a, b, c, d] = pos(y, x, n);
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny and ny < n and 0 <= nx and nx < n) {
                auto [na, nb, nc, nd] = pos(ny, nx, n);
                if(i == 0) uni(a, nc);
                else if(i == 1) uni(d, nb);
                else if(i == 2) uni(c, na);
                else uni(b, nd);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        for(int i = 0; i < n * n * 4; i++) uf[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                auto[a, b, c, d] = pos(i, j, n);
                merge(i,j,n);
                if(grid[i][j] == ' ') {
                    uni(a, b);
                    uni(b, c);
                    uni(c, d);
                } else if(grid[i][j] == '/') {
                    uni(a, b);
                    uni(c, d);
                } else {
                    uni(b, c);
                    uni(a, d);
                }
            }
        }
        unordered_set<int> us;
        for(int i = 0; i < n * n * 4; i++) {
            us.insert(find(i));
        }
        return us.size();
    }
};