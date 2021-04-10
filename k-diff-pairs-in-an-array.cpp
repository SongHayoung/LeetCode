class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;

        unordered_map<int, int> m;
        for(auto& num : nums) {
            m[num]++;
        }
        
        if(k == 0) {
            for(auto& num : m) {
                if(num.second >= 2)
                    res++;
            }
        } else {
            for(auto& num : m) {
                if(m.count(num.first + k))
                    res++;
            }
        }

        return res;
    }
};
