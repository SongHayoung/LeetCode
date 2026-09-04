class Solution {
public:
    int sortArray(vector<int>& nums, vector<int>& pre) {
        set<vector<int>> vis;
        queue<vector<int>> q;
        vector<int> ok(nums.size());
        iota(begin(ok), end(ok),0);
        auto push = [&](vector<int> A) {
            if(vis.count(A)) return;
            vis.insert(A);
            q.push(A);
        };
        int res = 0;
        auto apply = [&](vector<int> A, int p) {
            for(int i = 0, j = p - 1; i < j; i++,j--) swap(A[i],A[j]);
            return A;
        };
        push(nums);
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto vec = q.front(); q.pop();
                if(vec == ok) return res;
                for(auto& p : pre) {
                    push(apply(vec,p));
                }
            }
            res++;
        }
        return -1;
    }
};