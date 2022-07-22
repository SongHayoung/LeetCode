class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long sum = 1ll * k * threshold;
        long long window = 0;
        for(int i = 0; i < k; i++) {
            window += arr[i];
        }
        int res = window >= sum;
        for(int i = k; i < arr.size(); i++) {
            window += arr[i] - arr[i-k];
            res += window >= sum;
        }
        return res;
    }
};