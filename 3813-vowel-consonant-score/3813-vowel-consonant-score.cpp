class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        unordered_set<int> us{'a','e','i','o','u'};
        for(auto& ch : s) {
            if(!isalpha(ch)) continue;
            if(us.count(ch)) v++;
            else c++;
        }
        return c ? v / c : 0;
    }
};