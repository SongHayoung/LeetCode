class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        vector<pair<int,int>> A;
        for(int i = 0; i < nums.size(); i++) {
            if(A.size() == 0 or A.back().first != nums[i]) A.push_back({nums[i],1});
            else A.back().second++;
        }
        for(int i = 0; i < A.size(); i++) {
            if(A[i].first != 1) continue;
            res = max(res, A[i].second - (A.size() == 1));
            if(i + 2 < A.size() and A[i+1].second == 1) res = max(res, A[i].second + A[i+2].second);
        }
        return res;
    }
};