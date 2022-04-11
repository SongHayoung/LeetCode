class Solution {
    void addAndRemove(unordered_map<char, int>& m, char target, char unique, string s) {
        m[target] = m[unique];
        for(int i = 0; i < s.length(); i++) {
            m[s[i]] -= m[target];
        }

        return;
    }
public:
    string originalDigits(string s) {
        unordered_map<char, int> m;
        stringstream ss;
        for(int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }

        if(m.count('z') && m['z'] != 0) {
            addAndRemove(m, '0', 'z', "zero");
        }
        if(m.count('x') && m['x'] != 0) {
            addAndRemove(m, '6', 'x', "six");
        }
        if(m.count('g') && m['g'] != 0) {
            addAndRemove(m, '8', 'g', "eight");
        }
        if(m.count('u') && m['u'] != 0) {
            addAndRemove(m, '4', 'u', "four");
        }
        if(m.count('w') && m['w'] != 0) {
            addAndRemove(m, '2', 'w', "two");
        }
        if(m.count('f') && m['f'] != 0) {
            addAndRemove(m, '5', 'f', "five");
        }
        if(m.count('t') && m['t'] != 0) {
            addAndRemove(m, '3', 't', "three");
        }
        if(m.count('o') && m['o'] != 0) {
            addAndRemove(m, '1', 'o', "one");
        }
        if(m.count('s') && m['s'] != 0) {
            addAndRemove(m, '7', 's', "seven");
        }
        if(m.count('i') && m['i'] != 0) {
            addAndRemove(m, '9', 'i', "nine");
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