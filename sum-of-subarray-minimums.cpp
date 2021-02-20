class Solution {
private:
    int getJump(vector<int>& arr, vector<int>& jump, int cur) {
        int start = cur + 1;
        while(start < arr.size() && arr[cur] <= arr[start]) {
            start += jump[start];
        }
        return start - cur;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> jump(arr.size() + 1, 0);
        vector<int> memo(arr.size() + 1, 0);
        int res = 0;
        int mod = 1e9 + 7;
        for(int i = arr.size() - 1; i >= 0; --i) {
            jump[i] = getJump(arr, jump, i);
            res += (memo[i] = (arr[i] * jump[i] + memo[i + jump[i]]) % mod);
            res %= mod;
        }
        return res;
    }
