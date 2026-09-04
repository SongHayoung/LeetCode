class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;
        for(auto& n : nums) {
            if(res.size() == 0 or res.back() != n) res.push_back(n);
            else {
                long long x = n;
                while(res.size() and res.back() == x) {
                    res.pop_back(); x *= 2;
                }
                res.push_back(x);
            }
        }
        return res;
    }
};