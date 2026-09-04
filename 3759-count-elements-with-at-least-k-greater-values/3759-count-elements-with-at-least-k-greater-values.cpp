class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto& n : nums) freq[n]++;
        int res = 0, tot = nums.size();
        for(auto& [_,v] : freq) {
            tot -= v;
            if(tot >= k) res += v;
        }
        return res;
    }
};