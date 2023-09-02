class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string a = "", b = "", c = "", d = "";
        for(int i = 0; i < s1.length(); i++) {
            if(i & 1) b.push_back(s1[i]);
            else a.push_back(s1[i]);
        }
        for(int i = 0; i < s2.length(); i++) {
            if(i & 1) d.push_back(s2[i]);
            else c.push_back(s2[i]);
        }
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        sort(begin(c), end(c));
        sort(begin(d), end(d));
        return a == c and b == d;
    }
};