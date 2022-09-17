class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long res = 0, over = 0;
        vector<vector<long long>> A;
        for(auto& t : transactions) {
            long long c = t[0], b = t[1];
            if(b < c) A.push_back({c,b});
            else if(c <= b) over = max(over, c);
        }
        sort(begin(A), end(A), [](auto a, auto b) {
           return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        long long req = 0, ma = 0;
        for(auto& v : A) {
            long long c = v[0], b = v[1];
            req += c;
            res = max(res, req);
            req -= b;
            ma = max(ma, c);
        }
        return max({res, ma, req + over});
    }
};
