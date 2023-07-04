class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(auto n : nums)
            counter[n]++;
        for(auto [k,v] : counter)
            if(v==1)
                return k;
        return -1;
    }
};