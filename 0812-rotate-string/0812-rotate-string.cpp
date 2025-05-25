class Solution {
    int booth(string& s) {
        int n = s.length(), res = 0;
        string ss = s + s;
        vector<int> fail(2 * n, - 1);
        for(int j = 1; j < 2 * n; j++) {
            int i = fail[j-res-1];
            while(i != -1 and ss[j] != ss[res + i + 1]) {
                if(ss[j] < ss[res + i + 1]) res = j - i - 1;
                i = fail[i];
            }
            if(i == -1 and ss[j] != ss[res + i + 1]) {
                if(ss[j] < ss[res + i + 1]) res = j;
                fail[j - res] = -1;
            } else fail[j - res] = i + 1;
            if(res >= n) break;
        }
        return res < n ? res : res - n;
    }
    string helper(string& s) {
        int p = booth(s);
        return s.substr(p) + s.substr(0,p);
    }
public:
    bool rotateString(string s, string goal) {
        return helper(s) == helper(goal);
    }
};