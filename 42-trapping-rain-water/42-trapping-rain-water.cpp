class Solution {
public:
    int trap(vector<int>& h) {
        int res = 0, l = 0, r = h.size() - 1;
        int lmax = 0, rmax = 0;
        
        while(l < r) {
            if(h[l] < h[r]) {
                while(l < r and h[l] <= lmax) {
                    res += lmax - h[l];
                    l++;
                }
                lmax = h[l];
            } else {
                while(l < r and h[r] <= rmax) {
                    res += rmax - h[r];
                    r--;
                }
                rmax = h[r];
            }
        }
        return res;
    }
};