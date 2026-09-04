using ll = long long;

const ll mod = 1000000007;
const int MAX_N = 20202;
const int LOG = 22;

struct Matrix {
    ll a[2][2];

    Matrix(ll v = 0) {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = v;
    }
};

Matrix mul(const Matrix& x, const Matrix& y) {
    Matrix z(0);

    z.a[0][0] = (x.a[0][0] * y.a[0][0] + x.a[0][1] * y.a[1][0]) % mod;
    z.a[0][1] = (x.a[0][0] * y.a[0][1] + x.a[0][1] * y.a[1][1]) % mod;
    z.a[1][0] = (x.a[1][0] * y.a[0][0] + x.a[1][1] * y.a[1][0]) % mod;
    z.a[1][1] = (x.a[1][0] * y.a[0][1] + x.a[1][1] * y.a[1][1]) % mod;

    return z;
}

Matrix identityMatrix() {
    Matrix m(0);
    m.a[0][0] = 1;
    m.a[1][1] = 1;
    return m;
}

vector<int> children[MAX_N];
int up[MAX_N][LOG];
Matrix prod[MAX_N][LOG];
int depthArr[MAX_N];

void dfsBuild(int u) {
    for(int v : children[u]) {
        depthArr[v] = depthArr[u] + 1;
        up[v][0] = u;

        for(int j = 1; j < LOG; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
            prod[v][j] = mul(prod[v][j - 1], prod[up[v][j - 1]][j - 1]);
        }

        dfsBuild(v);
    }
}

int lcaQuery(int u, int v) {
    if(depthArr[u] < depthArr[v]) swap(u, v);

    int diff = depthArr[u] - depthArr[v];

    for(int j = 0; j < LOG; j++) {
        if(diff >> j & 1) {
            u = up[u][j];
        }
    }

    if(u == v) return u;

    for(int j = LOG - 1; j >= 0; j--) {
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

ll waysToAncestor(int u, int anc, int color) {
    ll x0 = color == 0;
    ll x1 = color == 1;

    int diff = depthArr[u] - depthArr[anc];

    for(int j = 0; j < LOG; j++) {
        if(diff >> j & 1) {
            Matrix& m = prod[u][j];

            ll y0 = (x0 * m.a[0][0] + x1 * m.a[1][0]) % mod;
            ll y1 = (x0 * m.a[0][1] + x1 * m.a[1][1]) % mod;

            x0 = y0;
            x1 = y1;
            u = up[u][j];
        }
    }

    return (x0 + x1) % mod;
}

class Solution {
public:
    int distinctPaths(int n, vector<int>& parent, vector<vector<int>>& gates, vector<vector<int>>& queries) {
        Matrix id = identityMatrix();

        for(int i = 0; i < n; i++) {
            children[i].clear();
            depthArr[i] = 0;

            for(int j = 0; j < LOG; j++) {
                up[i][j] = 0;
                prod[i][j] = id;
            }
        }

        for(int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        for(int i = 0; i < n; i++) {
            ll red = gates[i][0];
            ll blue = gates[i][1];
            ll white = gates[i][2];

            prod[i][0] = Matrix(0);
            prod[i][0].a[0][0] = blue;
            prod[i][0].a[0][1] = white;
            prod[i][0].a[1][0] = white;
            prod[i][0].a[1][1] = red;
        }

        for(int j = 0; j < LOG; j++) {
            up[0][j] = 0;
            prod[0][j] = id;
        }

        dfsBuild(0);

        int res = 0;

        for(auto& q : queries) {
            int a = q[0];
            int ac = q[1];
            int b = q[2];
            int bc = q[3];

            int g = lcaQuery(a, b);

            ll x = waysToAncestor(a, g, ac);
            ll y = waysToAncestor(b, g, bc);

            res ^= int(x * y % mod);
        }

        return res;
    }
};