class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(!k) return 0;
        int res = 0, head = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
            if(m.size() > k) {
                int p(INT_MAX);
                char c;
                for(auto& e : m) {
                    if(e.second < p) {
                        p = e.second; c = e.first;
                    }
                }
                m.erase(c);
                head = p + 1;
            }
            res = max(res, i - head + 1);
        }
        return res;
    }
};
