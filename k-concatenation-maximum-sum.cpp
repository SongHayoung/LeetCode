class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        vector<long long> sum(arr.size() + 1, 0);
        long long answer = 0;
        long long maxValue = 0;
        long long minValue = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum[i + 1] = sum[i] + arr[i];
            maxValue = max(maxValue, sum[i + 1]);
            minValue = min(minValue, sum[i + 1]);

            answer = max(answer, sum[i + 1] - minValue);
        }

        if(k > 1) {
            answer = max(answer, max(sum.back() - minValue + maxValue, sum.back() * (k - 1) + max(sum.back() - minValue, maxValue)));
        }

        if(k > 2) {
            answer = max(answer, sum.back() * (k - 2) + sum.back() - minValue + maxValue);
        }

        return max(sum.back() * k, answer) % 1000000007;
    }
};
