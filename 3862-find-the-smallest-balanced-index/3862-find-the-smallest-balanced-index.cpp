class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum = 0;
        map<int,int> right;
        for(int i = 1; i < nums.size(); i++) right[-nums[i]]++;
        for(int i = 0; i < nums.size(); i++) {
            long long prod = 1;
            for(auto& [k,v] : right) {
                int val = -k;
                if(val == 1) continue;
                for(int j = 0; j < v; j++) {
                    prod *= val;
                    if(prod > sum) break;
                }
                if(prod > sum) break;
            }
            if(prod == sum) return i;
            if(sum > prod) return -1;
            sum += nums[i];
            if(i + 1 < nums.size())
                if(--right[-nums[i+1]] == 0) right.erase(-nums[i+1]);
        }
        return -1;
    }
};