class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        long long t = 0, sum = 0;
        for(auto& c : cus) {
            if(c[0] > t) {
                t = c[0] + c[1];
                sum += c[1];
            } else {
                t += c[1];
                sum += t - c[0];
            }
        }
        return 1.0 * sum / cus.size();
    }
};
