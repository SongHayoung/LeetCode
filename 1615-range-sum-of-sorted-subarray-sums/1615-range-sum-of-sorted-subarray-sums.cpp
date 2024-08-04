#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vall3 vector<array<ll,3>>
#define all5 array<ll,5>
#define vall5 vector<all5>
#define vll vector<ll>
#define vs vector<string>
#define usll unordered_set<ll>
#define vvs vector<vs>
#define vvll vector<vll>
#define all(a) begin(a), end(a)

using namespace std;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pll, vpll, greater<pll>> pq;
        ll res = 0, mod = 1e9 + 7;
        for(ll i = 0; i < n; i++) pq.push({nums[i], i + 1});
        for(ll i = 1; i <= right; i++) {
            auto [v, p] = pq.top(); pq.pop();
            if(i >= left)
                res = (res + v) % mod;
            if(p < n)
                pq.push({v + nums[p], p + 1});
        }
        return res;
    }
};