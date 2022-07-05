bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int pSum(0), res(0);
        vector<pair<int, int>> pairs;
        for(int i = 0; i < p.size(); i++) {
            pairs.push_back({p[i], g[i]});
        }
        sort(begin(pairs), end(pairs), compare);
        for(int i = 0; i < p.size(); i++) {
            res = max(res, pSum + pairs[i].first + pairs[i].second);
            pSum += pairs[i].first;
        }
        return res;
    }
};