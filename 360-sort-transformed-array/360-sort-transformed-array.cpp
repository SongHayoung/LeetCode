class Solution {
    int transform(int n, int a, int b, int c) {
        return a * n * n + b * n + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int l = 0, r = nums.size() - 1;
        int index = a >= 0 ? r : l;
        vector<int> res(r+1);

        while(l <= r) {
            int left = transform(nums[l], a, b, c), right = transform(nums[r], a, b, c);
            if(a >= 0) {
                res[index--] = max(left, right);
                if(left > right) l++;
                else r--;
            } else {
                res[index++] = min(left, right);
                if(left < right) l++;
                else r--;
            }
        }
        return res;
    }
};