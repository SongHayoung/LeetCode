class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int len = s.length();
        bool mono = true;
        for(int i = 0; i < len - 1 and mono; i++) {
            if(s[i] > s[i + 1]) mono = false;
        }
        if(mono) return n;
        
        for(int i = 0; i < len - 1; i++) {
            if(s[i] > s[i + 1]) {
                char v = s[i];
                int j = i;
                while(j - 1 >= 0 and s[j - 1] == v) j--;
                s[j] -= 1;
                j += 1;
                for(; j < len; j++)
                    s[j] = '9';
                break;
            }
        }
        
        return stoi(s);
    }
};