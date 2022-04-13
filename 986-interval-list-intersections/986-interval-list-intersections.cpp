class Solution {
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        return {max(v1.front(), v2.front()), min(v1.back(), v2.back())};
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> res;
        int i(0), j(0);
        while(i < f.size() && j < s.size()) {
            vector<int> inter = intersect(f[i], s[j]);
            if(inter.front() <= inter.back()) {
                res.push_back(inter);
            }
            if(f[i].back() > s[j].back()) j++;
            else i++;
        }
        
        return res;
    }
};