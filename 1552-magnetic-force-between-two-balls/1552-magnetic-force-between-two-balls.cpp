class Solution {
    int search(vector<int>& p, int m) {
        int res = 1;
        for(int i = 1, last = p[0]; i < p.size(); i++) {
            if(last + m > p[i]) continue;
            last = p[i];
            res++;
        }
        return res;
    }
public:
    int maxDistance(vector<int>& p, int k) {
        sort(begin(p), end(p));
        int l = 1, r = p.back() - p[0];
        while(l <= r) {
            int m = l + (r - l) / 2;
            int s = search(p, m);
            if(s >= k) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};