class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int current = 1;
        bool isChecked[128] = {false};
        int head = 0, tail = 0;

        for(tail = 0; tail < s.length(); tail++, current++) {
            if(isChecked[s[tail]]) {
                while(s[head] != s[tail]) {
                    isChecked[s[head++]] = false;
                    current--;
                }
                head++;
                current--;
            } else {
                isChecked[s[tail]] = true;
            }
            if(result < current)
                result = current;
        }

        return result;
    }
};
