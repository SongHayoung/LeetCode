class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26);
        for(auto& ch : s1) freq[ch-'a']++;
        vector<int> now(26);
        int x = s1.length();
        for(int i = 0; i < s2.length(); i++) {
            now[s2[i]-'a']++;
            if(i >= x) {
                now[s2[i-x]-'a']--;
            }
            if(i + 1 >= x) {
                if(now == freq) return true;
            }
        }
        return false;
    }
};