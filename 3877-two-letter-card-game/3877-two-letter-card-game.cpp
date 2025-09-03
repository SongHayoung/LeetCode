class Solution {
public:
    int score(vector<string>& cards, char x) {
        int ox[10]{0}, xo[10]{0}, oo = 0, lr = 0;
        for(auto& c : cards) {
            if(c[0] == x and c[1] == x) oo++;
            else if(c[0] == x) ox[c[1]-'a']++,lr++;
            else if(c[1] == x) xo[c[0]-'a']++,lr++;
        }
        if(oo >= lr) return lr;

        auto helper = [&](int cnt[10]) {
            int sum = 0, ma = 0;
            for(int i = 0; i < 10; i++) sum += cnt[i], ma = max(ma, cnt[i]);
            if(sum < 2) return 0;
            return min(sum / 2, sum - ma);
        };
        int cnt = lr - oo, internal = helper(ox) + helper(xo);
        return min(internal, cnt / 2) + oo;
    }
};