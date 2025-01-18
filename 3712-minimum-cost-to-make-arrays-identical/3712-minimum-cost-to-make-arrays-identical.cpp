class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long res = 0, n = arr.size(), ans = k;
        for(int i = 0; i < n; i++) res += abs(arr[i] - brr[i]);
        sort(begin(arr), end(arr));
        sort(begin(brr), end(brr));
        for(int i = 0; i < n; i++) ans += abs(arr[i] - brr[i]);
        return min(res,ans);
    }
};