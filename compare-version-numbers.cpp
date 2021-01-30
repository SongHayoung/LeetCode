class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1, v2, p1 = 0, p2 =0;
        while(p1 < version1.length() || p2 < version2.length()) {
            v1 = v2 = 0;
            for(; p1 < version1.length() && version1[p1] != '.'; p1++){
                v1 = (v1<<3) + (v1<<1) + (version1[p1] & 0b1111);
            }

            for(; p2 < version2.length() && version2[p2] != '.'; p2++){
                v2 = (v2<<3) + (v2<<1) + (version2[p2] & 0b1111);
            }
            p1++; p2++;
            if(v1 ^ v2)
                return v1 > v2 ? 1 : -1;
        }
        return 0;
    }
};
