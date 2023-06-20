class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        vector<int> res(n, -1);
        
        if(2*k > n) return res; //out of range
        
        long long sum = 0;
        for(int i = 0; i < 2*k; i++)
            sum += nums[i];
        for(int i = 2*k; i < n; i++) {
            sum += nums[i];
            
            res[i-k] = sum / (2*k + 1);
            
            sum -= nums[i-2*k];
        }
        
        return res;
    }
};