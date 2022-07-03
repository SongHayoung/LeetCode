class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int, vector<int>> counter;
        vector<int> res = {(int)-1e5, (int)1e5};
        int k = nums.size();
        for(int i = 0; i < k; i++) {
            for(auto& num : nums[i]) {
                counter[num].push_back(i);
            }
        }
        unordered_map<int, int> mp;
        int right;
        for(auto l = begin(counter), r = begin(counter); r != end(counter);) {
            while(r != end(counter) and k) {
                for(auto& pos : r->second) {
                    if(++mp[pos] == 1) k--;
                }
                r++;
            }
            
            while(l != r and !k) {
                int left = l->first, right = prev(r)->first;
                if(right - left < res[1] - res[0])
                    res = {left, right};
                for(auto& pos : l->second) {
                    if(--mp[pos] == 0) k++;
                }
                l++;
            }
        }
        return res;
    }
};