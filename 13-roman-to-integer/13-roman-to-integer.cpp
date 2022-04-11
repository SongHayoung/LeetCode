class Solution {

public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };
        unordered_map<char, map<char, int>> roman2 = {
                {'I', {{'V', 4}, {'X', 9}}},
                {'X', {{'L', 40}, {'C', 90}}},
                {'C', {{'D', 400}, {'M', 900}}}};
        int res = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                if(roman2[s[i]][s[i+1]]) {res += roman2[s[i]][s[i+1]]; i++;}
                else res += roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }
        return res;
    }
};