class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> lookup;
        for(auto n : nums) {
            if(lookup.count(n)) return true;
            lookup.insert(n);
        }
        return false;
    }
};