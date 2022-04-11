class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& v1, vector<int>& v2) {
           if(v1[0] == v2[0]) return v1[1] < v2[1];
            else return v1[0] > v2[0];
        });
        vector<vector<int>> res;
        for(auto v : people) {
            res.insert(res.begin() + v[1], v);
        }
        
        return res;
    }
};