
class Solution {
    long long helper(vector<vector<int>>  A, long long x, long long dep, long long sel) {
        if(sel == 3) return dep;
        if(dep == 2) return sel == 2 ? max(x * 1e5, x * -1e5) : 0;
        int pick = min((long long)A[dep].size(), 3 - sel);
        long long res = helper(A,x,dep + 1, sel);
        for(int i = 0; i < pick; i++) {
            long long now = x;
            for(int j = 0; j <= i; j++) now = now * A[dep][j];
            res = max(res, helper(A,now,dep + 1, sel + i + 1));
        }
        return res;
    }
public:
    long long maxProduct(vector<int>& nums) {
        vector<int> pos, neg;
        for(auto& n : nums) {
            if(n > 0) pos.push_back(n);
            else if(n < 0) neg.push_back(n);
        }
        sort(rbegin(pos),rend(pos));
        sort(begin(neg), end(neg));
        while(pos.size() > 3) pos.pop_back();
        while(neg.size() > 3) neg.pop_back();
        return helper({pos,neg}, 1ll, 0, 0);

    }
};