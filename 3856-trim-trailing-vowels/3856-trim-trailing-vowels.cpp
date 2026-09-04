class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> us{'a','e','i','o','u'};
        while(s.size() and us.count(s.back())) s.pop_back();
        return s;
    }
};