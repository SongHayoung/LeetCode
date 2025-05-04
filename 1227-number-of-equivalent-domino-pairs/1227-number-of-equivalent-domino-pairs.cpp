class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        int res = 0;
        for(auto& d : dominoes) {
            pair<int,int> p{min(d[0],d[1]),max(d[0],d[1])};
            res += mp[p]++;
        }
        return res;
    }
};