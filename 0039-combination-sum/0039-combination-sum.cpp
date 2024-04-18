class Solution {
    void helper(vector<vector<int>>& res, vector<int>& arr, int target, int pos, int sum, vector<int>& now) {
        if(target == sum) {
            res.push_back(now);
            return;
        }
        if(pos == arr.size() or sum > target) return;
        for(; sum <= target; sum += arr[pos], now.push_back(arr[pos])) {
            helper(res,arr,target,pos+1,sum,now);
        }
        while(now.size() and now.back() == arr[pos]) now.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        candidates.erase(unique(begin(candidates), end(candidates)), end(candidates));
        vector<int> now;
        vector<vector<int>> res;
        helper(res,candidates,target,0,0,now);
        return res;
    }
};