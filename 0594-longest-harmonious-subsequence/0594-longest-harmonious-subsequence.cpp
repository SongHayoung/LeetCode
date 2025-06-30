class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto& n : nums) freq[n]++;
        int res = 0;
        for(auto& [k,v] : freq) {
            if(freq.count(k+1)) res = max(res, v + freq[k+1]);
        }
        return res;
    }
};