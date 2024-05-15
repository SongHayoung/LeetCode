class Solution {
public:
    int minNumberOfFrogs(string s) {
        string t = "croak";
        unordered_map<char,int> freq;
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'c') freq[s[i]]++;
            else if(s[i] == 'r') {
                if(freq['c'] == 0) return -1;
                freq['c']--;
                freq['r']++;
            } else if(s[i] == 'o') {
                if(freq['r'] == 0) return -1;
                freq['r']--;
                freq['o']++;
            } else if(s[i] == 'a') {
                if(freq['o'] == 0) return -1;
                freq['o']--;
                freq['a']++;
            } else if(s[i] == 'k') {
                if(freq['a'] == 0) return -1;
                freq['a']--;
                freq['k']++;
            } 
            int now = 0;
            for(auto& [_,cnt] : freq) now += cnt;
            res = max(res, now);
            freq['k'] = 0;
        }
        for(auto& [_,cnt] : freq) if(cnt) return -1;
        return res;
    }
};