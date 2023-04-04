class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> freq;
        int res = 1;
        for(auto& ch : s) {
            if(freq.count(ch)) {
                freq.clear();
                res++;
            }
            freq.insert(ch);
        }
        return res;
    }
};
