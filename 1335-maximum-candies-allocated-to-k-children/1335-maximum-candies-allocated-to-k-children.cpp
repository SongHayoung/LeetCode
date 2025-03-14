class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        int l = 1, r = *max_element(begin(c), end(c)), res = 0;
        while(l <= r) {
            int m = l + (r-l)/2;
            long long sum = 0;
            for(auto& n : c) {
                sum += (n / m);
            }
            if(sum < k) {
                r = m - 1;
            } else {
                l = m + 1;
                res = max(res, m);
            }
        }
        return res;
    }
};