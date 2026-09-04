class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& t) {
        unordered_map<int,int> f;
        for(auto& n : t) f[n]++;
        vector<int> res;
        for(auto& [k,v] : f) if(v % 2 ) res.push_back(k);
        sort(begin(res), end(res));
        return res;
    }
};