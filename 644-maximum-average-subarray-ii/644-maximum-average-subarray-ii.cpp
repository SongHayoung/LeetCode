class Solution {
    bool search(vector<int>& nums, int k, double t) {
        double sum = 0, psum = 0, minsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] - t;
            if(i >= k) {
                psum += nums[i-k] - t;
                minsum = min(psum, minsum);
            }
            if(i >= k - 1 and sum > minsum) return true;
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end());;
        while(l + 1e-5 < r) {
            double m = (l + r) / 2;
            if(search(nums,k,m)) l = m;
            else r = m;
        }
        return l;
    }
};