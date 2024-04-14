class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int> A;
        for(int i = 0; i < points.size(); i++) A.push_back(points[i][0]);
        sort(rbegin(A), rend(A));
        int res = 0;
        while(A.size()) {
            int until = A.back() + w;
            while(A.size() and A.back() <= until) A.pop_back();
            res++;
        }
        return res;
    }
};
