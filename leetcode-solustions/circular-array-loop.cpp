class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        int sz = nums.size(), g = 1;
        vector<int> gr(nums.size(), 0);
        for (int i = 0; i < sz; i++, g++) {
            if (gr[i] || !(abs(nums[i]) % sz)) {
                nums[i] = 0;
                continue;
            }

            bool flag = nums[i] > 0;
            int pos = i;
            do {
                int prev = pos;
                pos += nums[pos];
                nums[prev] = 0;
                gr[prev] = g;
                if (pos >= sz)
                    pos -= sz * (pos / sz);
                else if (pos < 0)
                    pos += sz * ((-pos / sz) + 1);

                if ((flag && nums[pos] < 0) || (!flag && nums[pos] > 0) || (nums[pos] && !(abs(nums[pos]) % sz)))
                    break;

                if (gr[pos] == gr[i])
                    return true;
                
            } while (nums[pos]);

        }
        return false;
    }
};
