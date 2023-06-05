class Solution {
    pair<int, int> degree(vector<int>& p1, vector<int>& p2) {
        int y = p2[1] - p1[1];
        int x = p2[0] - p1[0];
        int gcd = __gcd(y,x);
        return {y / gcd, x / gcd};
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        auto d = degree(coordinates[0], coordinates[1]);
        for(int i = 2; i < coordinates.size(); i++) {
            if(degree(coordinates[0], coordinates[i]) != d)
                return false;
        }
        return true;
    }
};