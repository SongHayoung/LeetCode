class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto& a, auto& b) {
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int l = -1, r = -1, res = 0;
        for(auto a : A) {
            int f = a[0], e = a[1];
            if(f <= l) continue;
            if(f > r) {
                r = e;
                l = e - 1;
                res += 2;
            } else {
                l = r;
                r = e;
                res += 1;
            }
        }
        return res;
    }
};