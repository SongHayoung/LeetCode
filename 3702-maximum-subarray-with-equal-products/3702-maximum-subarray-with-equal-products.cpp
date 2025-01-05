class Solution {
    vector<int> factors(int x) {
        vector<int> res(10);
        for(int i = 2; i * i <= x; i++) {
            while(x % i == 0) {
                res[i]++;
                x /= i;
            }
        }
        if(x != 1) res[x]++;
        return res;
    }
    void merge(vector<int>& A, vector<int>& B, function<int(int, int)> func) {
        for(int i = 0; i < A.size(); i++) A[i] = func(A[i],B[i]);
    }
public:
    int maxLength(vector<int>& nums) {
        vector<vector<int>> ops;
        for(int i = 1; i <= 10; i++) ops.push_back(factors(i));
        int res = 0, n = nums.size();
        auto ma = [&](int x, int y) {
            return max(x,y);
        };
        auto mi = [&](int x, int y) {
            return min(x,y);
        };
        auto add = [&](int x, int y) {
            return x + y;
        };
        auto ok = [&](vector<int>& p, vector<int>& g, vector<int>& l) {
            for(int i = 0; i < p.size(); i++) {
                if(p[i] != g[i] + l[i]) return false;
            }
            return true;
        };
        for(int i = 0; i < n; i++) {
            vector<int> p(10), g(10), l(10);
            merge(p,ops[nums[i]-1],ma);
            merge(g,ops[nums[i]-1],ma);
            merge(l,ops[nums[i]-1],ma);
            if(ok(p,g,l)) res = max(res, 1);
            for(int j = i + 1; j < n; j++) {
                merge(p,ops[nums[j]-1],add);
                merge(g,ops[nums[j]-1],mi);
                merge(l,ops[nums[j]-1],ma);
                if(ok(p,g,l)) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};