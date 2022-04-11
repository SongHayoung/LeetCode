class Solution {
public:
    string findContestMatch(int n) {
        vector<string> m(n);
        for(int i = 0; i < n; i++) {
            m[i] = to_string(i+1);
        }
        while(n) {
            for(int i = 0; i < n / 2; i++) {
                m[i] = '('+m[i]+','+m[n-i-1]+')';
            }
            
            n>>=1;
        }
        return m[0];
    }
};