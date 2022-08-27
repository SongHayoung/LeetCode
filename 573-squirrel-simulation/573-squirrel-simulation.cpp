class Solution {
    int distance(vector<int>& A, vector<int>& B) {
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int res = INT_MAX;
        int sum = 0;
        vector<pair<int, int>> B;
        for(auto& nut : nuts) {
            B.push_back({distance(nut, tree), distance(squirrel, nut)});
            sum += B.back().first * 2;
        }
        for(auto& [t, s] : B) {
            res = min(res, sum - t + s);
        }
        return res;
    }
};