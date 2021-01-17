class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> countsOfRectangles;
        for(vector<int> vec : rectangles) {
            countsOfRectangles[min(vec[0], vec[1])]++;
        }
        return (--countsOfRectangles.end())->second;
    }
};
