class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto& x : nums) freq[x]++;
        unordered_map<int,int> best;
        for(auto& [k,v] : freq) {
            if(!best.count(v)) best[v] = INT_MAX;
            best[v] = min(best[v], k);
        }
        if(best.size() == 1) return {-1,-1};
        vector<int> res;
        for(auto& [k,v] : best) res.push_back(v);
        sort(begin(res), end(res));
        while(res.size() > 2) res.pop_back();
        return res;
    }
};