class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis{INT_MIN};
        vector<int> res;
        for(auto& o : obstacles) {
            if(o >= lis.back()) {
                lis.push_back(o);
                res.push_back(lis.size() - 1);
            } else {
                auto it = upper_bound(lis.begin(), lis.end(), o);
                *it = o;
                res.push_back(it - begin(lis));
            }
        }
        return res;
    }
};