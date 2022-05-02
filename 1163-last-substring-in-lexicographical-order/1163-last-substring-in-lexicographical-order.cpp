class Solution {
public:
    string lastSubstring(string s) {
        int n = s.length(), res = n - 1, i = n - 1;
        
        while(i >= 0) {
            if(s[i] > s[res]) {
                res = i;
            } else if(s[i] == s[res]) {
                int j = 1;
                
                while(res + j < n and s[res + j] == s[i + j] and i + j != res) j++;
                if(res + j >= n or s[res + j] <= s[i + j])
                    res = i;
                
            }
            i--;
        }
        
        return s.substr(res);
    }
};