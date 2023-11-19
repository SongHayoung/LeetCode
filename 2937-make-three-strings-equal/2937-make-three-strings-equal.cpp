class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int res = 0;
        while(1) {
            if(s1.length() == 0 or s2.length() == 0 or s3.length() == 0) return -1;
            if(s1 == s2 and s2 == s3) return res;
            int len = max({s1.length(), s2.length(), s3.length()});
            if(s1.length() == len) s1.pop_back(), res += 1;
            if(s2.length() == len) s2.pop_back(), res += 1;
            if(s3.length() == len) s3.pop_back(), res += 1;
            if(s1.length() == 0 or s2.length() == 0 or s3.length() == 0) return -1;
        }
        return -1;
    }
};