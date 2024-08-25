class Solution {
    bool ok(int x, int y) {
        int a[4]{}, b[4]{}, p = 0;
        while(x or y) {
            if(x % 10 != y % 10) {
                a[p] = x % 10;
                b[p] = y % 10;
                p++;
            }
            x /= 10;
            y /= 10;
            if(p == 4) break;
        }
        if(p <= 1) return p == 0;
        if(x != y) return false;

        if(p <= 3) {
            sort(begin(a), end(a));
            sort(begin(b), end(b));
            return a[0] == b[0] and a[1] == b[1] and a[2] == b[2] and a[3] == b[3];
        }
        for(int i = 0; i < 3; i++) {
            for(int j = i + 1; j < 4; j++) {
                if(a[i] == b[j] and a[j] == b[i]) {
                    sort(begin(a), end(a));
                    sort(begin(b), end(b));
                    return a[0] == b[0] and a[1] == b[1] and a[2] == b[2] and a[3] == b[3];
                }
            }
        }
        return false;
    }
public:
    int countPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<string, unordered_map<int,int>> freq;
        for(int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            while(s.size() < 7) s.push_back('0');
            sort(begin(s), end(s));
            freq[s][nums[i]]++;
        }
        for(auto& [_,mp] : freq) {
            for(auto it = begin(mp); it != end(mp); it++) {
                res += it->second * (it->second - 1) / 2;
                for(auto jt = next(it); jt != end(mp); jt++) {
                    if(ok(it->first, jt->first)) res += it->second * jt->second;
                }
            }
        }
        return res;
    }
};