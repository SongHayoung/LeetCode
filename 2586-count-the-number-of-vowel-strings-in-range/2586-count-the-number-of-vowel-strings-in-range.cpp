class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> us{'a','e','i','o','u'};
        int res = 0;
        for(int i = left; i <= right; i++) {
            if(us.count(words[i].front()) and us.count(words[i].back())) res += 1;
        }
        return res;
    }
};
