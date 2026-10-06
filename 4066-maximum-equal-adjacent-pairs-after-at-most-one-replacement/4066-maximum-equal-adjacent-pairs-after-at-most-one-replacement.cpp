class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size(), best = 0, self = 0;
        unordered_map<int, unordered_map<int, int>> freq;
        for(int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i+1];
            if(a < b) swap(a,b);
            if(a == b) self++;
            else {
                best = max(best, ++freq[a][b]);
            }
        }
        return self + best;
    }
};