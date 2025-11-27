class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> R;
        for(int i = 0; i <= n; i++) R.push_back({i-ranges[i], i + ranges[i]});
        sort(rbegin(R), rend(R));
        int res = 0, until = 0, best = 0;
        while(R.size()) {
            auto [l,r] = R.back(); R.pop_back();
            if(l > until) {
                if(best < l) return -1;
                res++;
                cout<<until<<' '<<best<<endl;
                until = best;
                best = max(best, r);
            } else best = max(best, r);
        }
        if(until < n) {
            if(best >= n) return res + 1;
            return -1;
        }
        return res;
    }
};
