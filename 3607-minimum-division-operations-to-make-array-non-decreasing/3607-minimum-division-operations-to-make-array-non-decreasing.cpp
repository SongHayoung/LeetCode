class Solution {
    unordered_map<int,int> cache;
    int query(int x) {
        if(cache.count(x)) return cache[x];
        int sq = sqrt(x);
        for(int i = 2; i <= sq; i++) {
            if(x % i == 0) return cache[x] = x / i;
        }
        return cache[x] = 0;
    }
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= nums[i-1]) continue;
            int j = i - 1;
            while(j >= 0 and nums[j] > nums[j+1]) {
                int x = query(nums[j]);
                if(x == 0) return -1;
                res++;
                nums[j] /= x;
                if(nums[j] > nums[j+1]) return -1;
                j--;
            }
        }
        return res;
    }
};