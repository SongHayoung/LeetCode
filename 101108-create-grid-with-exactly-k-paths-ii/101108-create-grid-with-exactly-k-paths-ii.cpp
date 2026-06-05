class Solution {
public:
    vector<string> createGrid(int k) {
        vector<int> val(22);
        for (int i = 1; i <= 21; i++) {
            val[i] = i * (i + 1) / 2;
        }

        vector<vector<int>> prevSum(7, vector<int>(k + 1, -1));
        vector<vector<int>> used(7, vector<int>(k + 1, -1));

        prevSum[0][0] = 0;

        for (int i = 0; i < 6; i++) {
            for (int s = 0; s <= k; s++) {
                if (prevSum[i][s] == -1) continue;

                for (int m = 0; m <= 21; m++) {
                    int ns = s + val[m];
                    if (ns > k) continue;

                    if (prevSum[i + 1][ns] == -1) {
                        prevSum[i + 1][ns] = s;
                        used[i + 1][ns] = m;
                    }
                }
            }
        }

        if (prevSum[6][k] == -1) return {};

        vector<int> parts(6);
        int cur = k;
        for (int i = 6; i >= 1; i--) {
            parts[i - 1] = used[i][cur];
            cur = prevSum[i][cur];
        }

        vector<string> grid(25, string(25, '#'));

        for (int r = 0; r < 25; r++) {
            grid[r][0] = '.';
            grid[r][24] = '.';
        }

        for (int i = 0; i < 6; i++) {
            int m = parts[i];
            if (m == 0) continue;

            int base = i * 4;

            grid[base][1] = '.';

            for (int r = base; r <= base + 2; r++) {
                for (int c = 2; c <= m + 1; c++) {
                    grid[r][c] = '.';
                }
            }

            for (int c = m + 2; c < 25; c++) {
                grid[base + 2][c] = '.';
            }
        }

        return grid;
    }
};