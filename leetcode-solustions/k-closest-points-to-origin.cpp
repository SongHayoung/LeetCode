class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(begin(points), end(points), [](const vector<int>& a, const vector<int>& b) { return a.front() * a.front() + a.back() * a.back() < b.front() * b.front() + b.back() * b.back(); });
        return vector<vector<int>> (points.begin(), points.begin() + k);
    }
};
