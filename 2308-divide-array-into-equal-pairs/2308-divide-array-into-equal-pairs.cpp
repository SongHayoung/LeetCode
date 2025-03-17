class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n & 1) return false;
        unordered_set<int> s;
        for(int n : nums) {
            if(s.count(n)) s.erase(n);
            else s.insert(n);
        }
        return s.size() == 0;
    }
};
