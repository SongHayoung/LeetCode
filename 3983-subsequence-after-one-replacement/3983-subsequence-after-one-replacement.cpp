class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (n > m) return false;

        vector<int> f(n, -1), b(n, -1);

        for (int i = 0, j = 0; i < n and j < m; i++) {
            while (j < m and s[i] != t[j]) j++;
            if (j < m) f[i] = j++;
            else break;
        }

        for (int i = n - 1, j = m - 1; i >= 0 and j >= 0; i--) {
            while (j >= 0 and s[i] != t[j]) j--;
            if (j >= 0) b[i] = j--;
            else break;
        }

        if (f[n - 1] != -1) return true;

        if (n == 1) return m >= 1;

        if (b[1] != -1 and b[1] >= 1) return true;
        if (f[n - 2] != -1 and f[n - 2] + 1 < m) return true;

        for (int i = 1; i + 1 < n; i++) {
            if (f[i - 1] != -1 and b[i + 1] != -1 and f[i - 1] + 1 < b[i + 1]) {
                return true;
            }
        }

        return false;
    }
};