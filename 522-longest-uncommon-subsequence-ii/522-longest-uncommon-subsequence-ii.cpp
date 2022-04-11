class Solution {
private:
    bool isSubsequence(string& s1, string& s2) {
        int i, j;
        for(i = 0, j = 0; i < s1.length() && j < s2.length(); j++)
            if(s1[i] == s2[j])
                ++i;
        return i == s1.length();
    }
public:
    int findLUSlength(vector<string>& strs) {
        vector<bool> table(strs.size(), true);
        sort(strs.begin(), strs.end(), [](string& a, string&b) { return a.length() == b.length() ? a < b : a.length() < b.length();});
        for(int i = strs.size() - 1; i >= 0; --i) {
            bool flag = true;
            for(int j = strs.size() - 1; j >= 0; --j) {
                if(i == j) continue;
                if(isSubsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return strs[i].length();
        }

        return -1;
    }
};