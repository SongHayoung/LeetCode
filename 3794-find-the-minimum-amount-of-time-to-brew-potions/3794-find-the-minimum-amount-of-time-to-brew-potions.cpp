
struct line{
    long double m,b,l,r;
    line *left, *right;
    line(long double m, long double b, long double l, long double r) : m(m), b(b), l(l), r(r), left(nullptr), right(nullptr) {}
    long double eval(long double x) {
        return m * x + b;
    }
};
struct lichao {
    line* root;
    long double lBound, rBound;

    lichao(long double l, long double r): lBound(l), rBound(r), root(nullptr) {}

    void add(long double m, long double b) {
        add(root, lBound, rBound, m, b);
    }
    bool better(line*& node, long double m, long double b, long double x) {
        return (m * x + b) > node->eval(x);
    }
    void add(line*& node, long double l, long double r, long double m, long double b) {
        if(!node) {
            node = new line(m, b, l, r);
            return;
        }
        long double mid = (l + r) / 2.0L;
        bool lb = better(node,m,b,l), mb = better(node,m,b,mid);
        if(mb) {
            swap(node->m, m);
            swap(node->b, b);
        }
        if(r - l < 1e-9) return;
        if(lb ^ mb) {
            add(node->left, l, mid, m, b);
        } else add(node->right, mid, r, m, b);
    }

    long double query(long double x) {
        return query(root, lBound, rBound, x);
    }

    long double query(line* node, long double l, long double r, long double x) {
        if(!node) return -1e18;
        long double m = (l + r) / 2.0L;
        long double res = node->eval(x);
        if(x < m) {
            res = max(res, query(node->left, l, m, x));
        } else res = max(res, query(node->right, m, r, x));
        return res;
    }
};
class Solution {
public:

    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> A(n);
        A[0] = skill[0];
        for (int i = 1; i < n; i++) A[i] = A[i-1] + skill[i];
        lichao tree(0., 6000.);
        tree.add(0.,A[0]);

        for (int i = 1; i < n; i++) {
            long double slope = -A[i-1], intercept = A[i];
            tree.add(slope, intercept);
        }

        long long res = 0;
        for (int j = 0; j < m - 1; j++) {
            res += mana[j] * tree.query(1. * mana[j+1] / mana[j]) + 0.5;
        }
        return res + mana[m-1] * A[n-1];
    }
};