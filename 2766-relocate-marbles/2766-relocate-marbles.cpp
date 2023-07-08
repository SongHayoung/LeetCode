class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, int> freq;
        for(auto n : nums) freq[n] += 1;
        for(int i = 0; i < moveFrom.size(); i++) {
            int f = moveFrom[i], t = moveTo[i];
            if(f == t) continue;
            if(freq.count(f)) {
                freq[t] += freq[f];
                freq.erase(f);
            }
        }
        vector<int> res;
        for(auto [k,v] : freq) {
            res.push_back(k);
        }
        sort(begin(res), end(res));
        return res;
    }
};