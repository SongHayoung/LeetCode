class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(n == 1) return 0;
        if(n == 2) return s[0] > s[1] ? -1 : 0;
        string S = s;
        sort(begin(S), end(S));
        if(S == s) return 0;
        if(S.front() == s.front() or S.back() == s.back()) return 1;
        string SS = s;
        sort(begin(SS) + 1, end(SS));
        sort(begin(SS), end(SS) - 1);
        if(SS == S) return 2;
        SS = s;
        sort(begin(SS), end(SS) - 1);
        sort(begin(SS) + 1, end(SS));
        if(SS == S) return 2;
        return 3;
    }
};