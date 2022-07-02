class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int width = verticalCuts[0], height = horizontalCuts[0], mod = 1e9 + 7;
        for(int i = 1; i < horizontalCuts.size(); i++)
            height = max(height, horizontalCuts[i] - horizontalCuts[i - 1]);

        height = max(height, h - horizontalCuts.back());

        for(int i = 1; i < verticalCuts.size(); i++)
            width = max(width, verticalCuts[i] - verticalCuts[i - 1]);

        width = max(width, w - verticalCuts.back());

        return ((long)width * (long)height)%mod;
    }
};