class Solution {
    int parse(string& s, int &i) {
        int res = 0;
        while(i < s.length() and s[i] != '.') {
            res = res * 10 + (s[i++] & 0b1111);
        }
        i++;
        return res;
    }
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0;
        while(v1 < version1.length() or v2 < version2.length()) {
            int pv1 = parse(version1, v1);
            int pv2 = parse(version2, v2);
            if(pv1 > pv2) return 1;
            else if(pv1 < pv2) return -1;
        }
        return 0;
    }
};