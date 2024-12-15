vector<int> zfunction(deque<int>& s) {
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
    int beautifulSplits(vector<int>& nums) {
        deque<int> A(begin(nums), end(nums));
        int res = 0;
        vector<int> z1 = zfunction(A);
        for(int i = 1; i < z1.size(); i++) {
            A.pop_front();
            vector<int> z2 = zfunction(A);
            int until = z2.size();
            if(z1[i] >= i and nums.size() - 2 * i > 0) {
                res += nums.size() - i * 2;
                until = i;
            }
            for(int j = 1; j < until; j++) if(j <= z2[j]) res++;
        }
        return res;
    }
};