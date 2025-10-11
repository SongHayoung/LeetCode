class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        long long base = 1;
        while (n > 0) {
            int d = n % 10;
            if (d) res.push_back(d * base);
            n /= 10;
            base *= 10;
        }
        sort(res.begin(), res.end(), greater<int>());
        return res;
    }
};