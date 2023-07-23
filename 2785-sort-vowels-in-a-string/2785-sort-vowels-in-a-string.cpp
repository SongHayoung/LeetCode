class Solution {
public:
    string sortVowels(string s) {
        vector<int> cap;
        vector<char> v;
        unordered_set<char> us{'a','e','i','o','u'};
        for(int i = 0; i < s.length(); i++) {
            char ch = ::tolower(s[i]);
            if(us.count(ch)) {
                v.push_back(s[i]);
                cap.push_back(i);
            }
        }
        sort(begin(v), end(v));
        for(int i = 0; i < v.size(); i++) {
            s[cap[i]] = v[i];
        }
        return s;
    }
};