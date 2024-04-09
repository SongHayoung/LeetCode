class Solution {
public:
    string makeAntiPalindrome(string s) {
        vector<int> freq(26);
        for(auto& ch : s) freq[ch-'a']++;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > s.length() / 2) return "-1";
        }
        for(int i = 0, j = 0; i < s.length() / 2; i++) {
            while(freq[j] == 0) j++;
            s[i] = j + 'a';
            freq[j]--;
        }
        for(int i = s.length() / 2; i < s.length(); i++) {
            for(int j = 0; j < 26; j++) {
                if(!freq[j]) continue;
                if(j + 'a' == s[s.length() - i - 1]) continue;
                s[i] = 'a' + j;
                freq[j]--;
                break;
            }
        }
        return s;
    }
};
