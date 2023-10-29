class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, c1 = 0, c2 = 0;
        for(auto& n : nums1) {
            sum1 += n;
            if(n == 0) c1 += 1;
        }
        for(auto& n : nums2) {
            sum2 += n;
            if(n == 0) c2 += 1;
        }
        if(c1 == 0 and c2 == 0) {
            if(sum1 == sum2) return sum1;
            return -1;
        }
        if(c1 == 0) {
            if(sum2 + c2 <= sum1) return sum1;
            return -1;
        }
        if(c2 == 0) {
            if(sum1 + c1 <= sum2) return sum2;
            return -1;
        }
        return max(sum1 + c1, sum2 + c2);
    }
};
