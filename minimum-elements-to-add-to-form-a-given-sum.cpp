class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(auto& num : nums)
            sum += num;
        int cnt = abs(sum - goal) / limit + (abs(sum - goal) % limit == 0 ? 0 : 1);
        return cnt;
    }
};
