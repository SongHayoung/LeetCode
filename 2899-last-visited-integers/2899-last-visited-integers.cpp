class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen, ans;
        int ord = 0;
        for(auto& x : nums) {
            if(x == -1) {
                if(seen.size() <= ord) ans.push_back(-1);
                else ans.push_back(seen[seen.size() - ord - 1]);
                ord++;
            } else seen.push_back(x), ord = 0;
        }
        return ans;
    }
};