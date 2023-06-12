class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int> range;
        vector<string> res;
        for(auto n : nums) {
            if(range.empty()) {
                range.push_back(n);
                range.push_back(n);
            } else if(range.back() + 1 == n) {
                range.back() = n;
            } else {
                if(range[0] == range[1]) res.push_back(to_string(range.back()));
                else res.push_back(to_string(range[0])+"->"+to_string(range[1]));
                range.clear();
                range.push_back(n);
                range.push_back(n);
            }
        }
        if(!range.empty()) {
            if(range[0] == range[1]) res.push_back(to_string(range.back()));
            else res.push_back(to_string(range[0])+"->"+to_string(range[1]));
        }
        return res;
    }
};