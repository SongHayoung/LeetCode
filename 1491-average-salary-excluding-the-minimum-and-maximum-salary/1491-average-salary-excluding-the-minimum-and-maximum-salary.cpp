class Solution {
public:
    double average(vector<int>& salary) {
        int ma = INT_MIN, mi = INT_MAX, sum = 0, n = salary.size();
        for(auto s : salary) {
            ma = max(ma, s);
            mi = min(mi, s);
            sum += s;
        }
        sum = sum - mi - ma;
        return 1.0 * sum / (n-2);
    }
};