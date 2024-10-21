class Solution {
    int helper(string& s, int p, unordered_set<string>& us) {
        if(s.length() == p) return us.size();
        int res = 0;
        string cut = "";
        for(int i = p; i < s.length(); i++) {
            cut.push_back(s[i]);
            if(!us.count(cut)) {
                us.insert(cut);
                res = max(res, helper(s, i + 1, us));
                us.erase(cut);
            }
        }
        return res;
    }
public:
    int maxUniqueSplit(string s) {
        return helper(s, 0, unordered_set<string>() = {});
    }
};