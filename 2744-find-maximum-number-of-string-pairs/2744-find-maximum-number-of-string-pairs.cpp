class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> us;
        int res = 0;
        for(auto w : words) {
            if(us.count(w)) res += 1;
            reverse(begin(w), end(w));
            us.insert(w);
        }
        return res;
    }
};
