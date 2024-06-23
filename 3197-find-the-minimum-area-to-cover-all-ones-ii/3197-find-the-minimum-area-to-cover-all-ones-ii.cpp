#include <bits/stdc++.h>

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

using namespace std;

struct PairHash {inline std::size_t operator()(const std::pair<long long, long long> &v) const { return v.first * 31ll + v.second; }};

// speed
#define Code ios_base::sync_with_stdio(false);
#define By ios::sync_with_stdio(0);
#define Sumfi cout.tie(NULL);

// alias
using ll = long long;
using ld = long double;
using ull = unsigned long long;

// constants
const ld PI = acosl(-1.0);  /* pi */
const ll INF = 1e18;
const ld EPS = 1e-9;
const ll MAX_N = 101010;
const ll mod = 1e9+7;

// typedef
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef array<int,3> ai3;
typedef array<ll,3> all3;
typedef array<ll,4> all4;
typedef array<ll,5> all5;
typedef vector<all3> vall3;
typedef vector<all4> vall4;
typedef vector<all5> vall5;
typedef pair<ld, ld> pld;
typedef vector<pld> vpld;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef deque<ll> dqll;
typedef deque<pll> dqpll;
typedef pair<string, string> pss;
typedef vector<pss> vpss;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef unordered_set<ll> usll;
typedef unordered_set<pll, PairHash> uspll;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<pll, ll, PairHash> umpll;

// macros
#define precision(x) cout<<fixed;cout.precision(x);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,m,n) for(ll i=n;i>=m;i--)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define uniq(a) sort(all(a)), a.erase(unique(all(a)),end(a))
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define INF(a) memset(a,0x3f3f3f3f3f3f3f3fLL,sizeof(a))
#define NEGINF(a) memset(a,0xcf,sizeof(a))
#define ASCEND(a) iota(all(a),0)
#define sz(x) ll((x).size())
#define BIT(a,i) ((a>>i)&1)
#define BITSHIFT(a,i,n) (((a<<i) & ((1ll<<n) - 1)) | (a>>(n-i)))
#define MAXBIT(a) (64ll - __builtin_clzll(a) - 1ll)
#define MINBIT(a) (__builtin_ctzll(a))
#define pyes cout<<"YES\n";
#define pno cout<<"NO\n";
#define endl "\n"
#define pneg1 cout<<"-1\n";
#define ppossible cout<<"possible\n";
#define pimpossible cout<<"impossible\n";
#define TC(x) cout<<"Case #"<<x<<": ";
#define X first
#define Y second

// debug
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__);
#else
#define debug(...)
#endif

// utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template<typename T>
void printv(vector<T>v){ll n=v.size();rep(i,0,n){cout<<v[i];if(i+1!=n)cout<<' ';}cout<<endl;}
template<typename T>
void printvv(vector<vector<T>>v){ll n=v.size();rep(i,0,n)printv(v[i]);}
template<typename T>
void printvln(vector<T>v){ll n=v.size();rep(i,0,n)cout<<v[i]<<endl;}
void fileIO(string in = "input.txt", string out = "output.txt") {freopen(in.c_str(),"ma",stdin); freopen(out.c_str(),"w",stdout);}
void hackercupIO(string in) {fileIO("/Users/hayoungsong/Downloads/" + in, "/Users/hayoungsong/Downloads/solution.txt");}
void readf() {freopen("", "rt", stdin);}
template <typename... T>
void in(T &...a) { ((cin >> a), ...); }
template<typename T>
void in(vector<T>& v){rep(i,0,sz(v)) in(v[i]);}
template<typename T>
void in(deque<T>& v){rep(i,0,sz(v)) in(v[i]);}
template<typename T, typename U>
void in(pair<T,U>& A) {in(A.first, A.second);}
template<typename T, typename U>
void in(vector<pair<T,U>>& A) {rep(i,0,sz(A)) in(A[i]); }
template<typename T, std::size_t N>
void in(vector<array<T,N>>& A) {rep(i,0,sz(A)) rep(j,0,sz(A[i])) in(A[i][j]); }
template<typename T>
void in(vector<vector<T>>& A) {rep(i,0,sz(A)) in(A[i]);}

struct Combination {
    vll fac, inv;
    ll n, MOD;

    ll modpow(ll n, ll x, ll MOD = mod) { if(!x) return 1; ll res = modpow(n,x>>1,MOD); res = (res * res) % MOD; if(x&1) res = (res * n) % MOD; return res; }

    Combination(ll _n, ll MOD = mod): n(_n + 1), MOD(MOD) {
        inv = fac = vll(n,1);
        rep(i,1,n) fac[i] = fac[i-1] * i % MOD;
        inv[n - 1] = modpow(fac[n - 1], MOD - 2, MOD);
        rrep(i,1,n - 2) inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    ll fact(ll n) {return fac[n];}
    ll nCr(ll n, ll r) {
        if(n < r or n < 0 or r < 0) return 0;
        return fac[n] * inv[r] % MOD * inv[n-r] % MOD;
    }
};

struct Matrix {
    ll r,c,MOD;
    vvll matrix;
    Matrix(ll r, ll c, ll v = 0, ll MOD = mod): r(r), c(c), matrix(vvll(r,vll(c,v))), MOD(MOD) {}
    Matrix(vvll m, ll MOD = mod) : r(sz(m)), c(sz(m[0])), matrix(m), MOD(MOD) {}

    vector<ll>& operator[](ll pos) {return matrix[pos];}
    Matrix operator*(const Matrix& B) const {
        Matrix res(r, B.c, 0,MOD);
        rep(i,0,r) rep(j,0,B.c) rep(k,0,B.r) {
                    res[i][j] = (res[i][j] + matrix[i][k] * B.matrix[k][j] % MOD) % MOD;
                }
        return res;
    }

    Matrix copy() {
        Matrix copy(r,c,0,MOD);
        copy.matrix = matrix;
        return copy;
    }


    Matrix pow(ll n) {
        assert(r == c);
        Matrix res(r,r, 0,MOD);
        Matrix now = copy();
        rep(i,0,r) res[i][i] = 1;
        while(n) {
            if(n & 1) res = res * now;
            now = now * now;
            n /= 2;
        }
        return res;
    }

    ll det() {
        if(r == 1) return matrix[0][0];
        if(r == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        ll res = 0;
        rep(p,0,c) {
            Matrix mat(c-1,c-1);
            rep(i,1,r) rep(j,0,c) {
                    if(j == p) continue;
                    mat[i][j - (j >= p)] = matrix[i][j];
                }
            res += matrix[0][p] * (p & 1 ? -1 : 1) * mat.det();
        }
        return res;
    }
};

// geometry data structures
template <typename T>
struct Point {
    T y,x;
    Point(T y, T x) : y(y), x(x) {}
    Point(pair<T,T> p) : y(p.first), x(p.second) {}
    Point() {}
    void input() {cin>>y>>x;}
    friend ostream& operator<<(ostream& os, const Point<T>& p) { os<<p.y<<' '<<p.x<<'\n'; return os;}
    Point<T> operator+(Point<T>& p) {return Point<T>(y + p.y, x + p.x);}
    Point<T> operator-(Point<T>& p) {return Point<T>(y - p.y, x - p.x);}
    Point<T> operator*(ll n) {return Point<T>(y*n,x*n); }
    Point<T> operator/(ll n) {return Point<T>(y/n,x/n); }
    bool operator==(const Point<T> &a) {return x == a.x && y == a.y;}
    bool operator!=(const Point<T> &a) {return x != a.x or y != a.y;}
    bool operator<(const Point &other) const {if (x == other.x) return y < other.y;return x < other.x;}
    Point<T> rotate(Point<T> center, ld angle) {
        ld si = sin(angle * PI / 180.), co = cos(angle * PI / 180.);
        ld y = this->y - center.y;
        ld x = this->x - center.x;

        return Point<T>(y * co - x * si + center.y, y * si + x * co + center.x);
    }
    ld distance(Point<T> other) {
        T dy = abs(this->y - other.y);
        T dx = abs(this->x - other.x);
        return sqrt(dy * dy + dx * dx);
    }

    T norm() { return x * x + y * y; }
};

template<typename T>
struct Line {
    Point<T> A, B;
    Line(Point<T> A, Point<T> B) : A(A), B(B) {}
    Line() {}

    void input() {
        A = Point<T>();
        B = Point<T>();
        A.input();
        B.input();
    }

    T ccw(Point<T> &a, Point<T> &b, Point<T> &c) {
        T res = a.x * b.y + b.x * c.y + c.x * a.y;
        res -= (a.x * c.y + b.x * a.y + c.x * b.y);
        return res;
    }

    bool on(Point<T> x) {
        return ccw(A,x,B) == 0;
    }

    bool isIntersect(Line<T> o) {
        T p1p2 = ccw(A,B,o.A) * ccw(A,B,o.B);
        T p3p4 = ccw(o.A,o.B,A) * ccw(o.A,o.B,B);
        if (p1p2 == 0 && p3p4 == 0) {
            pair<T,T> p1(A.y, A.x), p2(B.y,B.x), p3(o.A.y, o.A.x), p4(o.B.y, o.B.x);
            if (p1 > p2) swap(p2, p1);
            if (p3 > p4) swap(p3, p4);
            return p3 <= p2 && p1 <= p4;
        }
        return p1p2 <= 0 && p3p4 <= 0;
    }

    pair<bool,Point<ld>> intersection(Line<T> o) {
        if(!this->intersection(o)) return {false, {}};
        ld det = 1. * (o.B.y-o.A.y)*(B.x-A.x) - 1.*(o.B.x-o.A.x)*(B.y-A.y);
        ld t = ((o.B.x-o.A.x)*(A.y-o.A.y) - (o.B.y-o.A.y)*(A.x-o.A.x)) / det;
        return {true, {A.y + 1. * t * (B.y - A.y), B.x + 1. * t * (B.x - A.x)}};
    }

    //@formula for : y = ax + pre
    //@return {a,pre};
    pair<ld, ld> formula() {
        T y1 = A.y, y2 = B.y;
        T x1 = A.x, x2 = B.x;
        if(y1 == y2) return {0, (ld)y1};
        if(x1 == x2) return {INF, (ld)x1};
        ld a = 1. * (y2 - y1) / (x2 - x1);
        ld b = -x1 * a + y1;
        return {a, b};
    }
};

template<typename T>
struct Circle {
    Point<T> center;
    T radius;
    Circle(T y, T x, T radius) : center(Point<T>(y,x)), radius(radius) {}
    Circle(Point<T> center, T radius) : center(center), radius(radius) {}
    Circle() {}

    void input() {
        center = Point<T>();
        center.input();
        cin>>radius;
    }

    bool circumference(Point<T> p) {
        return (center.x - p.x) * (center.x - p.x) + (center.y - p.y) * (center.y - p.y) == radius * radius;
    }

    bool intersect(Circle<T> c) {
        T d = (center.x - c.center.x) * (center.x - c.center.x) + (center.y - c.center.y) * (center.y - c.center.y);
        return (radius - c.radius) * (radius - c.radius) <= d and d <= (radius + c.radius) * (radius + c.radius);
    }

    bool include(Circle<T> c) {
        T d = (center.x - c.center.x) * (center.x - c.center.x) + (center.y - c.center.y) * (center.y - c.center.y);
        return d <= radius * radius;
    }
};

ll __gcd(ll x, ll y) { return !y ? x : __gcd(y, x % y); }
all3 __exgcd(ll x, ll y) { if(!y) return {x,1,0}; auto [g,x1,y1] = __exgcd(y, x % y); return {g, y1, x1 - (x/y) * y1}; }
ll __lcm(ll x, ll y) { return x / __gcd(x,y) * y; }
ll modpow(ll n, ll x, ll MOD = mod) {if(x<0){return modpow(modpow(n,-x,MOD),MOD-2,MOD);}n%=MOD;ll res=1;while(x){if(x&1){res=res*n%MOD;}n=n*n%MOD;x>>=1;}return res;}
ll __xor(ll n) {return n%4==0?n:n%4==1?1:n%4==2?n+1:0;}
ll __rangexor(ll l, ll r) {return __xor(r)^__xor(l-1);}

ll dp[3][33][33][33][33];
class Solution {
    ll helper(vvi& A, ll fl, ll y1, ll x1, ll y2, ll x2) {
        if(dp[fl][y1][x1][y2][x2] != -1) return dp[fl][y1][x1][y2][x2];
        ll& res = dp[fl][y1][x1][y2][x2] = INF;
        if(fl == 0) {
            pll r{INF,-INF}, c{INF,-INF};
            bool ok = false;
            rep(i,y1,y2) {
                rep(j,x1,x2) {
                    if(!A[i][j]) continue;
                    ok = true;
                    r.first = min(r.first, i);
                    r.second = max(r.second, i);
                    c.first = min(c.first, j);
                    c.second = max(c.second, j);
                }
            }
            if(!ok) return res = 0;
            return res = (r.second - r.first + 1) * (c.second - c.first + 1);
        }
        if(fl == 1) {
            rep(i,y1,y2) {
                res = min(res, helper(A,0,y1,x1,i + 1,x2) + helper(A,0,i+1,x1,y2,x2));
            }
            rep(j,x1,x2) {
                res = min(res, helper(A,0,y1,x1,y2,j + 1) + helper(A,0,y1,j+1,y2,x2));
            }
            return res;
        }
        if(fl == 2) {
            rep(i,y1,y2) {
                res = min(res, helper(A,1,y1,x1,i + 1,x2) + helper(A,0,i+1,x1,y2,x2));
                res = min(res, helper(A,0,y1,x1,i + 1,x2) + helper(A,1,i+1,x1,y2,x2));
            }
            rep(j,x1,x2) {
                res = min(res, helper(A,1,y1,x1,y2,j + 1) + helper(A,0,y1,j+1,y2,x2));
                res = min(res, helper(A,0,y1,x1,y2,j + 1) + helper(A,1,y1,j+1,y2,x2));
            }
            return res;
        }
        return res;
    }
public:
    int minimumSum(vector<vector<int>>& A) {
        MINUS(dp);
        return helper(A,2,0,0,sz(A),sz(A[0]));
    }
};