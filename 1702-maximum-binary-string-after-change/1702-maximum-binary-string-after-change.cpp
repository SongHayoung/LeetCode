class Solution {
public:
    string maximumBinaryString(string s) {
        int zero = count(begin(s), end(s), '0'), one = count(begin(s), end(s), '1');
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') one--;
            else return string(i,'1') + string(zero - 1, '1') + "0" + string(one, '1');
        }
        return s;
    }
};