class Solution {
public:
    int minUnlockedIndices(vector<int>& nums, vector<int>& locked) {
        map<int,deque<int>> at;
        for(int i = 0; i < nums.size(); i++) at[nums[i]].push_back(i);
        int res = 0, sorted = -1;
        while(at.size()) {
            int val = begin(at)->first;
            int ops = 0, lookup = sorted + 1, carry = false;
            for(auto& p : begin(at)->second) {
                if(p == sorted + 1) {
                    if(carry) {
                        res += ops;
                        ops = locked[p];
                    } else ops = 0;
                    sorted = p, lookup = p + 1;
                } else {
                    for(; lookup < p; lookup++) {
                        if(nums[lookup] > val + 1) return -1;
                        ops += locked[lookup];
                        if(nums[lookup] == val + 1) at[val+1].pop_front();
                        carry = true;
                    }
                    res += ops; ops = locked[p];
                    sorted = p;
                    lookup = p + 1;
                }
            }
            at.erase(begin(at));
        }
        return res;
    }
};