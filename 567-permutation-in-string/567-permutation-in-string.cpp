class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int n = s1.length();
        vector<int> v1(26,0);
        for(auto& ch : s1) v1[ch-'a']++;
        for(int i = 0; i < n; i++) v1[s2[i]-'a']--;
        bool check = true;
        for(int i = 0; i < 26; i++)
            if(v1[i]) {check = false; break;}
        if(check) return true;
        for(int i = n; i < s2.length(); i++) {
            v1[s2[i]-'a']--;
            v1[s2[i-n]-'a']++;
            check = true;
            for(int i = 0; i < 26; i++)
                if(v1[i]) {check = false; break;}
            if(check) return true;
        }
        
        return false;
    }
};