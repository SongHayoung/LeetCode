class Solution {
    int helper(vector<int>& w, int c) {
        int d = 1, handle = 0;
        for(auto& n : w) {
            handle += n;
            if(handle > c) {
                d++;
                handle = n;
            }
        }
        return d;
    }
public:
    int shipWithinDays(vector<int>& w, int days) {
        int l = *max_element(w.begin(), w.end()), r = accumulate(w.begin(),w.end(),0), res = INT_MAX;
        while(l <= r) {
            int m = l + (r-l) / 2;
            if(helper(w,m) <= days) {
                res = min(res,m);
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};