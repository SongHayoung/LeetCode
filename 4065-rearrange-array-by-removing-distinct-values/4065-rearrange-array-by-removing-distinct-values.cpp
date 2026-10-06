class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101);
        for(auto& n : nums) freq[n]++;
        int id = 0;
        auto lookup = [&]() {
            while(1) {
                if(freq[id]) {
                    --freq[id];
                    int res = id;
                    id = (id + 1) % 101;
                    return res;
                }
                id = (id + 1) % 101;
            }
        };
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = lookup();
        }
        return nums;
    }
};