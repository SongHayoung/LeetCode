class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(auto n : nums) {
            if(!s.count(n)) s.insert(n);
            else s.erase(n);
        }
        return vector<int>(s.begin(),s.end());
    }
};