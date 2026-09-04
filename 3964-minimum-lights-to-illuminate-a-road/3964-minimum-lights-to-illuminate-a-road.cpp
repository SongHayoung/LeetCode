class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size(), res = 0;
        vector<bool> on(lights.size());
        for(int i = 0, until = -1; i < n; i++) {
            if(lights[i]) until = max(until, i + lights[i]);
            if(until >= i) on[i] = 1;
        }
        for(int i = n - 1, until = n; i >= 0; i--) {
            if(lights[i]) until = min(until, i - lights[i]);
            if(until <= i) on[i] = 1;
        }
        auto ok = [&](int x) {
            return 0 <= x and x < n;
        };
        auto up = [&](int x) {
            for(auto& p : {-1,0,1}) if(ok(x+p)) on[x+p] = 1;
        };
        for(int i = 0; i < n; i++) {
            if(on[i]) continue;
            if(i == n - 1) up(i);
            else up(i+1);
            res++;
        }
        return res;
    }
};
