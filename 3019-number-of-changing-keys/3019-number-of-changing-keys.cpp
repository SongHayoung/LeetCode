class Solution {
public:
    int countKeyChanges(string s) {
        int res = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            char a = s[i], b = s[i+1];
            if(isupper(a)) a = tolower(a);
            if(isupper(b)) b = ::tolower(b);
            if(a != b) res += 1;
        } 
        return res;
    }
};

