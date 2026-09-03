
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        map<int,int> freq;
        for(auto& p : planks) freq[p]++;
        unordered_map<int,int> ffreq;
        for(auto it = begin(freq); it != end(freq); it++) {
            ffreq[it->first] += it->second;
            ffreq[it->first * 2] += it->second / 2;
            for(auto jt = next(it); jt != end(freq); jt++) {
                ffreq[it->first + jt->first] += min(it->second, jt->second);
            }
        }
        int res = 0;
        for(auto& [k,v] : ffreq) res = max(res, v);
        return res;
    }
};
