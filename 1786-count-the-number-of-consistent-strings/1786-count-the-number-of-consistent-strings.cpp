class Solution {
    int helper(string& s) {
        int res = 0;
        for(auto& ch : s) res |= 1ll<<(ch-'a');
        return res;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = helper(allowed);
        int res = 0;
        for(auto& w : words) if((helper(w) | mask) == mask) res++;

        return res;
    }
};