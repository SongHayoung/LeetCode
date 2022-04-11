class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //start, end pair
        unordered_map<int, int> range;
        unordered_map<int, unordered_map<int,int>::iterator> endOfRange;
        unordered_set<int> dup;
        int res = 0;
        for(auto n : nums) {
            if(dup.count(n)) continue; //skip duplication
            dup.insert(n);
            
            auto start = range.find(n + 1);
            if(start != range.end()) {
                auto newStart = range.insert({n, start->second}).first;
                endOfRange[start->second] = newStart; //update
                range.erase(start);
                res = max(res, newStart->second - newStart->first + 1);
                start = newStart;
            } else {
                start = range.insert({n,n}).first;
                endOfRange[n] = start;
                res = max(res, 1);
            }
            
            auto fin = endOfRange.find(n - 1);
            
            if(fin != endOfRange.end()) {
                auto prevStart = fin->second;
                prevStart->second = start->second;
                res = max(res, prevStart->second - prevStart->first + 1);
                endOfRange[start->second] = prevStart; //update
                range.erase(start);
            }
            
        }
        return res;
    }
};