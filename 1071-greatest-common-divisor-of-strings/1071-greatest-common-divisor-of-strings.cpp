class Solution {
    bool helper(string str1, string str2) {
        if(str1.size() % str2.size()) return false;
        int cnt = str1.size() / str2.size();
        string tmp = "";
        for(int i = 0; i < cnt; i++) tmp += str2;
        return tmp == str1;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        for(int i =  str2.length(); i >= 1; i--) {
            if(str2.length() % i) continue;
            if(str1.length() % i) continue;
            string cut = str2.substr(0,i);
            if(helper(str1,cut) and helper(str2,cut)) return cut;
        }
        return "";
    }
};