class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        if(n == 1) return 0;
        if(skill.size() == station.size()) return 1;
        vector<int> f(n), b(n);
        for(int i = 0, j = 0; i < n; j++) {
            if(skill[i] == station[j]) f[i++] = j;
        }
        for(int i = n - 1, j = station.size() - 1; i >= 0; j--) {
            if(skill[i] == station[j]) b[i--] = j;
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            res = max(res, b[i+1] - f[i]);
        }
        return res;
    }
};