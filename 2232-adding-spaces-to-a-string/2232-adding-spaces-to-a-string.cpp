class Solution {
public:
    string addSpaces(string s, vector<int>& A) {
        reverse(begin(A), end(A));
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            while(A.size() and A.back() <= i) {
                A.pop_back(); res.push_back(' ');
            }
            res.push_back(s[i]);
        }
        return res;
    }
};