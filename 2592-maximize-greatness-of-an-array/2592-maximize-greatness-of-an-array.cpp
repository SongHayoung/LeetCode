class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int res = 0;
        multiset<int> ms;
        for(auto a : nums) ms.insert(a);
        for(int a : nums) {
            auto it = ms.upper_bound(a);
            if(it == end(ms)) continue;
            ms.erase(it);
            res += 1;
        }
        return res;
    }
};