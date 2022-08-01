class Solution {
public:
    int countQuadruples(string A, string B) {
        unordered_map<char, int> mp;
        for(int i = 0; i < B.length(); i++)
            mp[B[i]] = i;
        int len = INT_MAX, res = 0;
        for(int i = 0; i < A.length(); i++) {
            if(!mp.count(A[i])) continue;
            int clen = i - mp[A[i]];
            if(clen == len) res++;
            else if(clen < len) {
                len = clen;
                res = 1;
            }
        }
        return res;
    }
};