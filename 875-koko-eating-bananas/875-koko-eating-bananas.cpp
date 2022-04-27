class Solution {
    long search(vector<int>& p, long m) {
        return accumulate(begin(p), end(p), 0l, [&](long sum, int b) {
           return sum + ceil(1.0 * b / m); 
        });
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long l = 1, r = INT_MAX;
        while(l <= r) {
            long m = (l + r) / 2;
            long s = search(piles, m);
            if(s > h) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};