class Solution {
    vector<string> trans(vector<string> p) {
        int n = p.size(), m = p[0].size();
        vector<string> q(m, string(n, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                q[j][i] = p[i][j];
            }
        }
        return q;
    }

    vector<string> build(int n, int m, vector<string> p) {
        int a = p.size(), b = p[0].size();
        vector<string> g(n, string(m, '#'));

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                g[i][j] = p[i][j];
            }
        }

        int r = a - 1, c = b - 1;

        for (int j = c; j < m; j++) {
            g[r][j] = '.';
        }

        for (int i = r; i < n; i++) {
            g[i][m - 1] = '.';
        }

        return g;
    }

    bool fit(int n, int m, vector<string>& p) {
        return (int)p.size() <= n && (int)p[0].size() <= m;
    }

public:
    vector<string> createGrid(int m, int n, int k) {
        vector<vector<string>> cand;

        if (k == 1) {
            cand.push_back({"."});
        } else if (k == 2) {
            cand.push_back({"..", ".."});
        } else if (k == 3) {
            cand.push_back({"...", "..."});
        } else {
            cand.push_back({"....", "...."});
            cand.push_back({"..#", "...", "#.."});
        }

        int maxPath = 1;
        for (int i = 1; i <= m - 1; i++) {
            maxPath = maxPath * (n - 1 + i) / i;
            if (maxPath >= k) break;
        }

        if (maxPath < k) return {};

        for (auto p : cand) {
            if (fit(m, n, p)) return build(m, n, p);

            auto q = trans(p);
            if (fit(m, n, q)) return build(m, n, q);
        }

        return {};
    }
};