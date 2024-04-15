class Solution {
    array<int,3> helper(vector<vector<int>>& A, int skip) {
        pair<int, int> sumMa{INT_MIN,-1}, sumMi{INT_MAX,-1};
        pair<int, int> diffMa{INT_MIN,-1}, diffMi{INT_MAX,-1};
        for(int i = 0; i < A.size(); i++) {
            if(i == skip) continue;
            int sum = A[i][0] + A[i][1];
            int diff = A[i][0] - A[i][1];
            if(sum > sumMa.first) sumMa = {sum, i};
            if(sum < sumMi.first) sumMi = {sum, i};
            if(diff > diffMa.first) diffMa = {diff, i};
            if(diff < diffMi.first) diffMi = {diff, i};
        }
        if(sumMa.first - sumMi.first > diffMa.first - diffMi.first) {
            return {sumMa.first - sumMi.first, sumMa.second, sumMi.second};
        }
        return {diffMa.first - diffMi.first, diffMa.second, diffMi.second};
    }
public:
    int minimumDistance(vector<vector<int>>& points) {
        auto [_,i,j] = helper(points, -1);
        return min(helper(points,i)[0], helper(points,j)[0]);
    }
};