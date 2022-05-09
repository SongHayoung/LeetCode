class Solution {
    long search(vector<int>& arr, long& m) {
        long res = 0;
        for(auto& n : arr)
            res += (n > m ? m : n);
        return res;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        long l = 0, r = *max_element(begin(arr), end(arr)), res = INT_MAX, diff = INT_MAX;
        while(l <= r) {
            long m = l + (r - l) / 2;
            long s = search(arr, m);
            if(abs(target - s) < diff) {
                res = m;
                diff = abs(target - s);
            } else if(abs(target - s) == diff and res > m) {
                res = m;
            }
            
            if(s >= target) r = m - 1;
            else l = m + 1;
        }
        return res;
    }
};