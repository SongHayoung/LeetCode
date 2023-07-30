class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(auto ch : s) {
            if(isalpha(ch)) res.push_back(::tolower(ch));
            else if(isdigit(ch)) res.push_back(ch);
        }
        for(int l = 0, r = res.size() - 1; l < r; l += 1, r -= 1) {
            if(res[l] != res[r]) return false;
        }
        return true;
    }
};