class Solution {
public:
    int maxArea(vector<int>& height) {
        // [1,8,6,2,5,4,8,3,7]
        // 0, 8 -> w : 8 and h : 1 -> 8
        // 1, 8 -> w : 7 and h : 7 -> 49
        // 1, 7 -> w : 6 and h : 3 -> 18
        // 1, 6 -> w : 5 and h : 8 -> 40
        // 
        // [8,1,8,8] w - 1, h <= 8
        // [8,9,8,8] 
        
        int area = 0, left = 0, right = height.size() - 1;
        while(left < right) {
            int length = right - left;
            int h = min(height[left], height[right]);
            area = max(area, length * h);
            if(height[left] < height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return area;
    }
};