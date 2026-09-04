class Solution {
public:
    int minOperations(vector<int>& nums) {
        int safe = nums.size();
        unordered_map<int,int> freq;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(++freq[nums[i]] == 2) break;
            safe = i;
        }
        int until = safe - 1;
        if(until == -1) return 0;
        return until / 3 + 1;
    }
};