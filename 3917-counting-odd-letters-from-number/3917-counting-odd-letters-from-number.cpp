class Solution {
    string digitToWord(char digit) {
        switch (digit) {
            case '0': return "zero";
            case '1': return "one";
            case '2': return "two";
            case '3': return "three";
            case '4': return "four";
            case '5': return "five";
            case '6': return "six";
            case '7': return "seven";
            case '8': return "eight";
            case '9': return "nine";
            default: return "";
        }
    }

public:
    int countOddLetters(int n) {
        string s = "";
        while(n) {
            s += digitToWord((n % 10) + '0');
            n /= 10;
        }
        vector<int> freq(26);
        for(auto& ch : s) freq[ch-'a']++;

        int res = 0;
        for(auto& cnt : freq) if(cnt & 1) res++;
        return res;
    }
};