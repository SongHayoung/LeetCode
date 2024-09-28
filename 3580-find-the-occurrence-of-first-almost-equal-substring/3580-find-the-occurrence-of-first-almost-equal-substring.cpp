vector<int> zfunction(string s) {
    int l = 0, r = 0, n = s.size();
    vector<int> z(n);
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n and s[r-l] == s[r]) r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if(z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while(r < n and s[r-l] == s[r]) r++;
                z[i] = r - l;
                r --;
            }
        }
    }
    return z;
}
class Solution {
public:
    int minStartingIndex(string& s, string& pattern) {
        string rs = s, rp = pattern;
        reverse(begin(rs), end(rs));
        reverse(begin(rp), end(rp));
        string s1 = pattern + "#" + s;
        string s2 = rp + "#" + rs;
        vector<int> z = zfunction(s1);
        vector<int> rz = zfunction(s2);
        int padd = pattern.size() + 1;
        for(int i = padd; i < s1.size() - pattern.size() + 1; i++) {
            if(z[i] + rz[s2.size() - (i - padd) - pattern.size()] + 1 >= pattern.size()) return i - padd;
        }
        return -1;
    }
};