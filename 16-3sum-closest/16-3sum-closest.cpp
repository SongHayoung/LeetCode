class Solution {
private:
    int getSum(vector<int> &nums, int p1, int p2, int p3) {
        return nums[p1] + nums[p2] + nums[p3];
    }

    int getAnswer(int num, int target, int compare) {
        return abs(num - target) >= abs(compare - target) ? compare : num;
    }

public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());

        int p1 = 0, p2 = 1, p3 = nums.size() - 1;
        int answer = getSum(nums, p1, p2, p3), comp;

        for (p1 = 0; p1 < nums.size() - 2 && nums[p1] * 3 <= target; p1++) {
            p2 = p1 + 1;
            p3 = nums.size() - 1;
            
            while (p2 < p3) {
                comp = getSum(nums, p1, p2, p3);
                answer = getAnswer(answer, target, comp);
                if (comp >= target)
                    p3--;
                else
                    p2++;
            }
        }

        return answer;
    }
};