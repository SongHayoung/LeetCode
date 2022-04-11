class Solution {
    queue<int> q[10];
    void radixSort(vector<int>& nums, int p) {
        int d = pow(10,p);
        
        for(int& n : nums) {
            int bucket = (n / d) % 10;
            q[bucket].push(n);
        }
        
        int index = 0;
        
        for(int i = 0; i <= 9; i++) {
            while(!q[i].empty()) {
                nums[index++] = q[i].front(); q[i].pop();
            }
        }
    }
public:
    int maximumGap(vector<int>& nums) {
        int d = log10(*max_element(begin(nums),end(nums)));
        for(int i = 0; i <= d; i++)
            radixSort(nums,i);
        
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            res = max(res, nums[i+1] - nums[i]);
        }
        return res;
    }
};