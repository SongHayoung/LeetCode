class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size(), res = INT_MAX;
        unordered_map<int,int> freq;
        for(auto& m : mat) for(auto& n : m) freq[n]++;
        for(auto& [k,v] : freq) if(v == n) res = min(res, k);
        return res == INT_MAX ? -1 : res;
    }
};