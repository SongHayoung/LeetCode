class Solution {
    bool helperTag(string& s, int& p) {
        int i = p;
        string tag = parseTag(s,i);
        if(tag == "") return false;
        if(!helperContent(s,i)) return false;
        int j = i + tag.length() + 3;
        if(j > s.length() or s.substr(i,j-i) != "</" + tag + ">") return false;
        p = j;
        return true;
    }
    string parseTag(string& s, int& l) {
        if(s[l] != '<') return "";
        int r = s.find('>',l);
        if(r == string::npos or r - 1 - l < 1 or 9 < r - 1  - l) return "";
        string tag = s.substr(l+1,r-1-l);
        for(auto& ch : tag) if(!isupper(ch)) return "";
        l = r + 1;
        return tag;
    }
    bool helperContent(string& s, int& p) {
        int i = p;
        while(i < s.length()) {
            if(!helperText(s,i) and !helperCData(s,i) and !helperTag(s,i)) break;
        }
        p = i;
        return true;
    }
    bool helperText(string& s, int& p) {
        int i = p;
        while(p < s.length() and s[p] != '<') p++;
        return i != p;
    }
    bool helperCData(string& s, int& p) {
        if(s.find("<![CDATA[",p) != p) return false;
        int r = s.find("]]>", p);
        if(r == string::npos) return false;
        p = r + 3;
        return true;
    }
public:
    bool isValid(string code) {
        int p = 0;
        return helperTag(code, p) and p == code.length();
    }
};