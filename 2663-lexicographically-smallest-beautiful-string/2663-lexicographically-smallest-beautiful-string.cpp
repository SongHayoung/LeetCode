using namespace std;

struct PairHash {inline std::size_t operator()(const std::pair<int, int> &v) const { return v.first * 31 + v.second; }};

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
const ld EPS = 1e-11;
const ll MAX_N = 101010;
const ll mod = 1e9 + 7;

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
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,m,n) for(ll i=n;i>=m;i--)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define INF(a) memset(a,0x3f3f3f3f3f3f3f3fLL,sizeof(a))
#define ASCEND(a) iota(all(a),0)
#define sz(x) ll((x).size())
#define BIT(a,i) ((a>>i)&1)
#define BITSHIFT(a,i,n) (((a<<i) & ((1ll<<n) - 1)) | (a>>(n-i)))
#define pyes cout<<"YES\n";
#define pno cout<<"NO\n";
#define endl "\n"
#define pneg1 cout<<"-1\n";
#define ppossible cout<<"Possible\n";
#define pimpossible cout<<"Impossible\n";
#define TC(x) cout<<"Case #"<<x<<": ";
#define X first
#define Y second

// utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template<typename T>
void printv(vector<T>v){ll n=v.size();rep(i,0,n){cout<<v[i];if(i+1!=n)cout<<' ';}cout<<endl;}
template<typename T>
void printvv(vector<vector<T>>v){ll n=v.size();rep(i,0,n)printv(v[i]);}
template<typename T>
void printvln(vector<T>v){ll n=v.size();rep(i,0,n)cout<<v[i]<<endl;}
void fileIO(string in = "input.txt", string out = "output.txt") {freopen(in.c_str(),"r",stdin); freopen(out.c_str(),"w",stdout);}
void readf() {freopen("", "rt", stdin);}
template <typename... T>
void in(T &...a) { ((cin >> a), ...); }
template<typename T>
void readv(vector<T>& v){rep(i,0,sz(v)) in(v[i]);}
template<typename T, typename U>
void readp(pair<T,U>& A) {cin>>A.first>>A.second;}
template<typename T, typename U>
void readvp(vector<pair<T,U>>& A) {rep(i,0,sz(A)) readp(A[i]); }
template<typename T>
void readvall(vector<T>& v) {rep(i,0,sz(v)) rep(j,0,sz(v[i])) in(v[i][j]);}
template<typename T>
void readvv(vector<vector<T>>& A) {rep(i,0,sz(A)) readv(A[i]);}

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

    Matrix operator*(const Matrix& B) const {
        Matrix res(r, B.c, 0,MOD);
        rep(i,0,r) rep(j,0,B.c) rep(k,0,B.r) {
                    res.matrix[i][j] = (res.matrix[i][j] + matrix[i][k] * B.matrix[k][j] % MOD) % MOD;
                }
        return res;
    }

    Matrix copy() {
        Matrix copy(r,c,0,MOD);
        copy.matrix = matrix;
        return copy;
    }

    ll get(ll y, ll x) {
        return matrix[y][x];
    }

    Matrix pow(ll n) {
        assert(r == c);
        Matrix res(r,r, 0,MOD);
        Matrix now = copy();
        rep(i,0,r) res.matrix[i][i] = 1;
        while(n) {
            if(n & 1) res = res * now;
            now = now * now;
            n /= 2;
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

    //@formula for : y = ax + fl
    //@return {a,fl};
    pair<ld, ld> formula() {
        T y1 = A.y, y2 = B.y;
        T x1 = A.x, x2 = B.x;
        if(y1 == y2) return {1e9, 0};
        if(x1 == x2) return {0, 1e9};
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
ll modpow(ll n, ll x, ll MOD = mod) { if(x < 0) return modpow(modpow(n,-x,MOD), MOD-2,MOD); n%=MOD; if(!x) return 1; ll res = modpow(n,x>>1,MOD); res = (res * res) % MOD; if(x&1) res = (res * n) % MOD; return res; }


//ll dp[101010][2][28][28];
class Solution {
    ll helper(string& s, int k, ll ch1, ll ch2, int p, bool high, string& me) {
  //      ll& res = dp[p][high][ch1][ch2];
        ll res = -2;
        //if(res != -1) return res;
        if(p == sz(s)) return res = high ? 0 : -2;
        res = -2;
        if(high) {
            rep(i,0,k) {
                if(i == ch1 or i == ch2) continue;
                me.push_back(i + 'a');
                if(helper(s,k,ch2,i,p+1,high,me) != -2) {
                    return res = i;
                }
                me.pop_back();
            }
            return res;
        }
        rep(i,s[p]-'a',k) {
            if(i == ch1 or i == ch2) continue;
            me.push_back(i + 'a');
            if(helper(s,k,ch2,i,p+1,i != s[p] - 'a',me) != -2) {
                return res = i;
            }
            me.pop_back();
        }
        return res;
    }
public:
    string smallestBeautifulString(string s, int k) {
       // MINUS(dp);
        string me = "";
        helper(s,k,27,27,0,false, me);
        return me;
    }
};
