const int MAX_N = 101010;
int fenwick[MAX_N];
void update(int n, int x) {
    while(n < MAX_N) {
        fenwick[n] += x;
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

class Solution {
    vector<int> compress(vector<int>& A) {
        auto S = A;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        unordered_map<int,int> mp;
        for(int i = 0; i < S.size(); i++) mp[S[i]] = i + 1;
        for(int i = 0; i < A.size(); i++) A[i] = mp[A[i]];
        return A;
    }
public:
    long long minInversionCount(vector<int>& nums, int k) {
        nums = compress(nums);
        int n = nums.size();
        memset(fenwick, 0, sizeof fenwick);
        long long res = LLONG_MAX, now = 0;
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                now -= query(nums[i-k] - 1);
                update(nums[i-k], -1);
            }
            update(nums[i], 1);
            now += min(i + 1, k) - query(nums[i]);
            if(i + 1 >= k) res = min(res, now);
        }
        return res;
    }
};