class Solution {
    int fenwick[2020];
    void update(int n, int v) {
        while(n < 2020) {
            fenwick[n] += v;
            n += n & -n;
        }
    }
    int query(int n) {
        int res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        memset(fenwick, 0, sizeof fenwick);
        vector<int> p(m + 1);
        for(int i = 1; i <= m; i++) {
            p[i] = m + i;
            update(p[i], 1);
        }
        vector<int> res;
        for(auto& q : queries) {
            res.push_back(query(p[q] - 1));
            update(p[q], -1);
            p[q] = m--;
            update(p[q], 1);
        }
        return res;
    }
};