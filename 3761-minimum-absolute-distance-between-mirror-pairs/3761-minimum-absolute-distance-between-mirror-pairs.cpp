class Solution {
    int rev(int x) {
        string s = to_string(x);
        int res = 0;
        while(s.length()) {
            res = res * 10 + s.back() - '0';
            s.pop_back();
        }
        return res;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> at;
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(at.count(nums[i])) res = min(res, i - at[nums[i]]);
            at[rev(nums[i])] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};