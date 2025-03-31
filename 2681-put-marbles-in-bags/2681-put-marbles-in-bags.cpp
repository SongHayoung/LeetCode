class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<long long> q1;
        priority_queue<long long, vector<long long>, greater<long long>> q2;
        for(int i = 0; i < weights.size() - 1; i++) {
            q1.push(weights[i] + weights[i+1]);
            q2.push(weights[i] + weights[i+1]);
        }
        long long res = 0;
        for(int i = 0; i < k - 1; i++) {
            res += q1.top() - q2.top();
            q1.pop();
            q2.pop();
        }
        return res;
    }
};