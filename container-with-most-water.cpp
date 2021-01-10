class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0, minHeight = height[0];
        bool isChecked[30002] = {false, };
        for(int i = 1; i < height.size(); i++) {
            answer = max(answer, i * min(height[0], height[i]));
        }

        isChecked[height[0]] = isChecked[0] = true;

        for(int i = 1; i < height.size(); isChecked[height[i++]] = true) {
            if(isChecked[height[i]] || height[i] <= minHeight) continue;
            minHeight = height[i];
            for(int j = height.size() - 1; j >= i + (answer / height[i]); j--) {
                answer = max(answer, (j - i) * min(height[i], height[j]));
            }
        }

        return answer;
    }
};
