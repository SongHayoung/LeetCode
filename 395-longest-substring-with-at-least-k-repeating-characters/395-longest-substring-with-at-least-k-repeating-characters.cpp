class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int arr[26];
        for(int uniq = 1; uniq <= 26; uniq++) {
            memset(arr,0,sizeof(arr));
            int l = 0, r = 0, cuniq = 0, overk = 0;
            while(r < s.length()) {
                if(cuniq <= uniq) {
                    if(!arr[s[r] - 'a']) cuniq++;
                    arr[s[r] - 'a']++;
                    if(arr[s[r] - 'a'] == k) overk++;
                    r++;
                } else {
                    if(arr[s[l]-'a'] == 1) cuniq--;
                    if(arr[s[l]-'a'] == k) overk--;
                    arr[s[l]-'a']--;
                    l++;
                }
                if(cuniq == uniq and cuniq == overk) {
                    res = max(res, r - l);
                }
            }
        }
        return res;
    }
};