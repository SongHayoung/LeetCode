class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res = "";
        int n = s.length();
        for(int i = 0; i < s.length(); i++) {
            res.push_back(s[(i+k)%n]);
        }
        return res;
    }
};