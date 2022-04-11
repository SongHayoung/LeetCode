class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> res;
        for(int i = 1; i <= nums.size(); i++)
            res.insert(i);
        
        for(auto& num : nums) {
            if(res.count(num))
                res.erase(num);
            else
                res.insert(num);
        }

        return vector<int> (res.begin(), res.end());
    }
};