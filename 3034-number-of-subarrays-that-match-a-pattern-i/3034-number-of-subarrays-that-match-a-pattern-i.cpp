
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            bool ok = true;
            for(int j = 0; j < pattern.size() and ok; j++) {
                if(i + j + 1 == nums.size()) ok = false;
                else {
                   if(pattern[j] == 1) {
                       if(nums[i+j+1] > nums[i+j]) continue;
                       ok = false;
                   } else if(pattern[j] == 0) {
                       if(nums[i+j+1] == nums[i+j]) continue;
                       ok = false;
                   } else if(pattern[j] == -1) {
                       if(nums[i+j+1] < nums[i+j]) continue;
                       ok = false;
                   }
                }
            }
            if(ok) res+=1;
        }
        return res;
    }
};
