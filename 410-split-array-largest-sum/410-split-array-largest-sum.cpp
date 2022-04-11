
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(m == 1) return sum;
        int l = *max_element(nums.begin(), nums.end()), r = sum;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            
            if(verifyArraySplitUnderM(nums, mid, m)) r = mid - 1;
            else l = mid + 1;
            
        }
        return l;
    }
    bool verifyArraySplitUnderM(vector<int>& nums, int mid, int m) {
        int sum = 0;
        for(auto& num : nums) {
            sum += num;
            if(sum > mid) {
                sum = num;
                m--;
                if(!m) return false;
            }
        }
        return true;
    }
};