class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(auto& a : arr) freq[a]++;
        int res = -1;
        for(auto& [k,v] : freq) if(k == v) res = max(res, v);
        return res;
    }
};