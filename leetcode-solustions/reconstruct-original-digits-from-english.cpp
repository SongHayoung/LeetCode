class Solution {
    void addAndRemove(unordered_map<char, int>& cnt, unordered_map<char, int>& m, char target, char unique, string s) {
        m[target] = cnt[unique];
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i]] -= m[target];
        }

        return;
    }
public:
    string originalDigits(string s) {
        unordered_map<char,int> cnt;
        unordered_map<char, int> m;
        stringstream ss;
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i]]++;
        }

        if(cnt.count('z') && cnt['z'] != 0) {
            addAndRemove(cnt, m, '0', 'z', "zero");
        }
        if(cnt.count('x') && cnt['x'] != 0) {
            addAndRemove(cnt, m, '6', 'x', "six");
        }
        if(cnt.count('g') && cnt['g'] != 0) {
            addAndRemove(cnt, m, '8', 'g', "eight");
        }
        if(cnt.count('u') && cnt['u'] != 0) {
            addAndRemove(cnt, m, '4', 'u', "four");
        }
        if(cnt.count('w') && cnt['w'] != 0) {
            addAndRemove(cnt, m, '2', 'w', "two");
        }
        if(cnt.count('f') && cnt['f'] != 0) {
            addAndRemove(cnt, m, '5', 'f', "five");
        }
        if(cnt.count('t') && cnt['t'] != 0) {
            addAndRemove(cnt, m, '3', 't', "three");
        }
        if(cnt.count('o') && cnt['o'] != 0) {
            addAndRemove(cnt, m, '1', 'o', "one");
        }
        if(cnt.count('s') && cnt['s'] != 0) {
            addAndRemove(cnt, m, '7', 's', "seven");
        }
        if(cnt.count('i') && cnt['i'] != 0) {
            addAndRemove(cnt, m, '9', 'i', "nine");
        }
        
        
        for(char i = '0'; i <= '9'; i++) {
            if(m.count(i)) {
                while(m[i]) {
                    ss<<i;
                    m[i]--;
                }
            }
        }

        return ss.str();
    }
};
