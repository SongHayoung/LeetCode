class Solution {
private:
    bool isFinish = false;
    bool isDesc(vector<int>& nums, vector<int>& cnt, int& MAX) {
        bool flag = true;
        cnt[nums[0]]++;
        MAX = max(MAX, nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i - 1])
                flag = false;
            MAX = max(MAX, nums[i]);
            cnt[nums[i]]++;
        }

        return flag;
    }

    void recursive(vector<int>& nums, vector<int>& tmp, vector<int>& cnt, const int max, int pos, bool flag) {
        if(pos == nums.size()) {
            if(flag){
                nums = tmp;
                isFinish = true;
            }
            return ;
        }

        for(int i = flag == 1 ? 0 : nums[pos]; i <= max; ++i) {
            if(!cnt[i]) continue;
            cnt[i]--;
            tmp[pos] = i;
            recursive(nums, tmp, cnt, max, pos + 1, flag ? flag : nums[pos] < i);
            if(isFinish)
                return ;
            cnt[i]++;
        }
        return ;
    }
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        vector<int> cnt(101,0);
        int max = 0;
        if(isDesc(nums, cnt, max)) {
            sort(begin(nums), end(nums));
            return;
        }
        vector<int> res(nums.size());
        recursive(nums, res, cnt, max, 0, false);
        return ;
    }
};
