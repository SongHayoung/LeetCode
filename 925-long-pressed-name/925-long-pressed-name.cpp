class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.length() < name.length()) return false;
        int i = 0, j = 0;
        for(; i < name.length() and j < typed.length();) {
            while(i < name.length() and j < typed.length() and name[i] == typed[j]) {
                i++; j++;
            }
            while(i > 0 and j < typed.length() and name[i-1] == typed[j]) j++;
            if(i < name.length() and j < typed.length() and name[i] != typed[j]) return false;
        }
        return i == name.length() and j == typed.length();
    }
};