class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int res1 = edges[0][0], res2 = edges[0][1];
        if(edges[1][0] == res1 or edges[1][1] == res1) return res1;
        return res2;
    }
};