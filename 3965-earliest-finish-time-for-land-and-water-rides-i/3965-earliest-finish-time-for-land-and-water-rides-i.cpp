class Solution {
    int helper(vector<pair<int,int>>& A, vector<pair<int,int>>& B) {
        int end = INT_MAX;
        for(auto& [start, fin] : A) end = min(fin, end);
        int res = INT_MAX;
        for(auto& [start, fin] : B) {
            int ride = max(fin, fin - start + end);
            res = min(res, ride);
        }
        return res;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>> land, water;
        for(int i = 0; i < landStartTime.size(); i++) {
            land.push_back({landStartTime[i], landStartTime[i] + landDuration[i]});
        }
        for(int i = 0; i < waterStartTime.size(); i++) {
            water.push_back({waterStartTime[i], waterStartTime[i] + waterDuration[i]});
        }
        return min(helper(land, water), helper(water, land));
    }
};