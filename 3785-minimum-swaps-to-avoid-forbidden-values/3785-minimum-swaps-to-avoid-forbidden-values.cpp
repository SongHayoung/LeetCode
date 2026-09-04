class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i = 0; i < n; i++) if(nums[i] == forbidden[i]) freq[nums[i]]++;
        int best = 0, tot = 0;
        for(auto& [k,v] : freq) {
            best = max(best, v);
            tot += v;
        }
        if(best * 2 <= tot) return (tot + 1) / 2;
        int res = tot - best, remain = 2 * best - tot, who = -1;
        for(auto& [k,v] : freq) if(v == best) who = k;
        for(int i = 0; i < n and remain; i++) if(nums[i] != forbidden[i] and forbidden[i] != who and nums[i] != who) {
            remain--;
            res++;
        }
        return remain ? -1 : res;
    }
};