class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char> v{'a','e','o','i','u'};
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            int vc = 0, cc = 0;
            for(int j = i; j < s.length(); j++) {
                if(v.count(s[j])) vc += 1;
                else cc += 1;
                if(vc == cc and vc * cc % k == 0) res += 1;
            }
        }
        return res;
    }
};