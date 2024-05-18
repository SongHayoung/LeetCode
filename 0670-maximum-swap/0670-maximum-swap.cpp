class Solution {
    string helper(string s) {
        int idx1 = -1, idx2 = -1, n = s.length();
        for(int i = n - 1, best = -1, at = -1; i >= 0; i--) {
            int x = s[i] - '0';
            if(best > x) {
                idx1 = i;
                idx2 = at;
            }
            if(best < x) {
                best = x;
                at = i;
            }
        }
        
        if(idx1 == -1) return s;
        swap(s[idx1],s[idx2]);
        return s;
    }
public:
    int maximumSwap(int num) {
        return stoi(helper(to_string(num)));
    }
};