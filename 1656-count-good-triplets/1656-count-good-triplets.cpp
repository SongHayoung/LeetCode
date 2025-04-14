class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        vector<int> pre(1010);
        int res = 0, n = arr.size();
        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(abs(arr[j] - arr[k]) > b) continue;
                int mi = max({0,arr[j] - a, arr[k] - c}), ma = min({arr[j] + a, arr[k] + c, 1000}) + 1;
                if(mi > ma) continue;
                res += pre[ma] - pre[mi];
            }

            for(int i = arr[j] + 1; i < pre.size(); i++) pre[i]++;
        }
        return res;
    }
};