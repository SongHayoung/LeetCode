class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int idx = max_element(begin(nums), end(nums)) - begin(nums);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i != idx) sum = (sum + (i < idx ? 1 : -1) * nums[i]);
        }
        return sum > 0 ? 0 : sum < 0 ? 1 : -1;
    }
};