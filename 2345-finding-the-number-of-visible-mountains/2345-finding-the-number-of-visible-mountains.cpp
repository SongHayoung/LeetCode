class Solution {
    string toString(vector<int>& A) {
        string res = "";
        for(auto& a : A) res += to_string(a) + '#';
        return res;
    }
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        int res = 0, n = peaks.size();
        unordered_map<string, int> freq;
        for(auto& p : peaks) freq[toString(p)]++;
        vector<array<int,3>> A;
        for(auto& p : peaks) {
            if(freq[toString(p)] > 1) continue;
            int x = p[0], y = p[1];
            A.push_back({x-y,y,x+y});
        }
        sort(begin(A), end(A), [](auto a, auto b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int bound = -1;
        for(auto& [l, h, r] : A) {
            if(bound < r) {
                res++;
                bound = r;
            }
        }
        return res;
    }
};