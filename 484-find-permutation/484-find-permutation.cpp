class Solution {
    int countD(string& s, int i) {
        int cnt = 0;
        while(i < s.length() and s[i++] == 'D') cnt++;
        return cnt;
    }
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        int mi = 1;
        while(res.size() < s.length()) {
            if(s[res.size()] == 'I') res.push_back(mi++);
            else {
                int count = countD(s,res.size());
                int nextMi = mi + count + 1;
                while(count--) {
                    res.push_back(count + 1 + mi);
                }
                res.push_back(mi);
                mi = nextMi;
            }
        }
        if(s.back()  == 'I')
            res.push_back(mi);
        return res;
    }
};