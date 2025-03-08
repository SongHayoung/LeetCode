class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k > 26 or s.length() < k) return 0;
        int arr[26]{0,}, l = 0, r = 0, n = s.length(), res = 0;
        
        while(r < n) {
            arr[s[r++]-'a']++;
            while(arr[s[r-1]-'a'] > 1 or l + k < r) {
                arr[s[l++]-'a']--;
            }
            if(l + k == r){
             res++;   
            }
        }
        return res;
    }
};