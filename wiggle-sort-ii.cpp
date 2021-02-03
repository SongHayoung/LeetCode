class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 2) {
            sort(nums.begin(), nums.end());
            return ;
        }
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        int tail = nums.size() - 1, head = tail>>1, pos = 0;
        while(head >= 0) {
            nums[pos++] = sorted[head--];
            if(tail >= nums.size()/2)
                nums[pos++] = sorted[tail--];
        }
    }
};
