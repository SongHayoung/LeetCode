class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, now = 0;
        for(auto g : gain) res = max(res, now += g);
        return res;
    }
};