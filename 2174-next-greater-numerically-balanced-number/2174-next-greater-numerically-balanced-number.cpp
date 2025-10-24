class Solution {
    int helper(int n, string s, int mask, int len, int now) {
        if(len > s.length() + 1) return INT_MAX;
        if(now == 10) {
            string s = to_string(n);
            if(len < s.length()) return INT_MAX;
            string o = "";
            for(int i = 1; i <= 9; i++) {
                if(mask & (1<<i))
                    o += string(i,i+'0');
            }
            do{
                int perm = stoi(o);
                if(perm > n) return perm;
            }while(next_permutation(begin(o),end(o)));
            return INT_MAX;
        }
        return min(helper(n, s, mask, len, now + 1), helper(n, s, mask | (1<<now), len + now, now + 1));
    }
public:
    int nextBeautifulNumber(int n) {
        return helper(n, to_string(n), 0, 0, 1);
    }
};