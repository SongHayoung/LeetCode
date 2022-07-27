class Solution {
public:
    int minimumOperations(vector<int>& A, int start, int goal) {
        queue<int> q;
        q.push(start);
        unordered_set<int> vis;
        vis.insert(start);
        int res = 1;
        while(!q.empty() and res <= 1000) {
            int sz = q.size();
            while(sz--) {
                auto n = q.front(); q.pop();
                for(auto& a : A) {
                    if(a + n == goal or n - a == goal or (a ^ n) == goal) {
                        return res;
                    }
                    if(0 <= a + n and a + n <= 1000 and !vis.count(a+n)) {
                        vis.insert(a+n);
                        q.push(a+n);
                    }
                    if(0 <= n - a and n - a <= 1000 and !vis.count(n - a)) {
                        vis.insert(n-a);
                        q.push(n-a);
                    }
                    if(0 <= (a ^ n) and (a ^ n) <= 1000 and !vis.count(a ^ n)) {
                        vis.insert(a^n);
                        q.push(a^n);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};