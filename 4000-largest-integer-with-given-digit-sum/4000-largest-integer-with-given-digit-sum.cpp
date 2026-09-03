class Solution {
public:
    int largestInteger(int n, int s) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            int d = min(s, 9);
            res = res * 10 + d;
            s -= d;
        }
        return s ? -1 : res;
    }
};