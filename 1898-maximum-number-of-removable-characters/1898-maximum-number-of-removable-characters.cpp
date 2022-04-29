class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size();
        vector<int> rm(s.size(), INT_MAX);
        for (int i = 0; i < removable.size(); ++i) rm[removable[i]] = i;
        while (l < r) {
            int m = (l + r + 1) / 2, j = 0;
            for (int i = 0; i < s.size() && j < p.size(); ++i) {
                if (rm[i] >= m && s[i] == p[j])
                    ++j;
            }
            if (j == p.size()) l = m;
            else r = m - 1;
        }
        return l;
    }
};