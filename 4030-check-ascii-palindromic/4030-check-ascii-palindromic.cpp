class Solution {
public:
    bool isPalindromic(string s) {
        string ss;
        for(auto& ch : s) {
            ss += format("{:08b}", ch);
        }
        cout<<ss<<endl;
        for(int l = 0, r = ss.size() - 1; l < r; l++,r--) {
            if(ss[l] != ss[r]) return false;
        }
        return true;
    }
};