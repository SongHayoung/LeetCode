class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> fl(nums.size());
        vector<int> ord(nums.size());
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i], ord[i] = i;
        sort(begin(ord), end(ord), [&](int i, int j) {
            if(nums[i] == nums[j]) return i > j;
            return nums[i] > nums[j];
        });
        vector<long long> res;
        for(auto& q : queries) {
            if(!fl[q[0]]) {
                sum -= nums[q[0]];
                fl[q[0]] = true;
            }
            while(q[1] and ord.size()) {
                while(ord.size() and fl[ord.back()] == 1) ord.pop_back();
                if(ord.size()) {
                    q[1]--;
                    sum -= nums[ord.back()];
                    fl[ord.back()] = 1;
                    ord.pop_back();
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};