class Solution {
    long _validStoi(string s) {
        return s[0] == '0' ? s == "0" ? 0 : 256 : s.length() > 3 ? 256 : stoi(s);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip1, ip2, ip3, ip4;
        for(int i1 = 0; i1 < s.length(); i1++) {
            ip1 += s[i1]; ip2 = "";
            if(_validStoi(ip1) > 255) break;
            for(int i2 = i1 + 1; i2 < s.length(); i2++) {
                ip2 += s[i2]; ip3 = "";
                if(_validStoi(ip2) > 255) break;
                for(int i3 = i2 + 1; i3 < s.length() - 1; i3++) {
                    ip3 += s[i3]; ip4 = s.substr(i3 + 1);
                    if(_validStoi(ip3) > 255) break;
                    if(_validStoi(ip4) > 255) continue;
                    res.push_back(ip1 + "."  + ip2 + "." + ip3 + "." + ip4);
                }
            }
        }
        return res;
    }
};