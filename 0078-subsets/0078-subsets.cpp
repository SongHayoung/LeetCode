class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(auto& n: nums){
            int sz = res.size();
            for(int i = 0; i < sz; i++){
                vector<int> tmp = res[i];
                tmp.push_back(n);
                res.push_back(tmp);
            }
        }
        return res;
    }
};