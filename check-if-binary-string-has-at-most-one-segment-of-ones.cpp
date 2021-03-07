class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = true;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == '0')
                flag = false;
            else if(s[i] == '1' && !flag)
                return false;
        }
        return true;
    }
};
