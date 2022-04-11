class Solution {
    int getDistance(vector<int>& v1, vector<int>& v2) {
        return (v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            unordered_map<int, int> lookup;
            for(int j = 0; j < points.size(); j++) {
                if(i == j) continue;
                int distance = getDistance(points[i], points[j]);
                lookup[distance]++;
            }
            for(auto [_, v]: lookup)
                res += v * (v-1);

        }
        return res;
    }
};