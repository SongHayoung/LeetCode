class Solution {
public:
    string pushDominoes(string s) {
        int l = 0, r = s.length() - 1;
        while(l <= r and s[l] != 'R') {
            if(s[l] == 'L') {
                for(int i = l - 1; i >= 0 and s[i] == '.'; i--) s[i] = 'L';
            }
            l++;
        }
        while(l <= r and s[r] != 'L') {
            if(s[r] == 'R') {
                for(int i = r + 1; r < s.length() and s[i] == '.'; i++) s[i] = 'R';
            }
            r--;
        }
        while(l <= r) {
            while(l <= r and s[l] != 'R') {
            if(s[l] == 'L') {
                for(int i = l - 1; i >= 0 and s[i] == '.'; i--) s[i] = 'L';
            }
            l++;
        }
            if(l >= r) break;
            int lr = l + 1;
            while(lr < r and s[lr] == '.') lr++;
            if(s[lr] == 'R') {
                for(int i = l; i <= lr; i++) {
                    s[i] = 'R';
                }
            } else if(s[lr] == 'L') {
                for(int i = l, j = lr; i < j; i++, j--) {
                    s[i] = 'R'; s[j] = 'L';
                }
            }
            
            l = lr + (s[lr] == 'L');
        }
        
        return s;
    }
};