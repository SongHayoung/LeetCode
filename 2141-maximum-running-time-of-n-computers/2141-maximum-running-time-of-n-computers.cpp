class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0ll);
        sort(batteries.begin(), batteries.end());
        for(int i = batteries.size() - 1; i >= 0; i--) {
            if(batteries[i] > sum / n) {
                sum -= batteries[i];
                n--;
            } else {
                return sum / n;
            }
        }
        return sum / n;
    }
};