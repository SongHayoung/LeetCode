class Solution {
public:
    int minOperations(string s, int k) {
        int now = std::count(s.begin(), s.end(), '1');
        int n = s.length();
        if(now == n) return 0;
        if(k % 2 == 0) {
            if((now ^ n) & 1) return -1;
        }
        set<int> st[2];
        if(k % 2 == 0) {
            for(int i = now & 1; i <= n; i += 2) st[i&1].insert(i);
        } else for(int i = 0; i <= n; i++) st[i&1].insert(i);
        queue<int> q;
        int res = 1, fl = k & 1;
        q.push(now);
        st[now&1].erase(now);
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                int x = q.front(); q.pop();
                int until = abs((n - x) - k);
                int del = -1;
                int xbit = x & 1;
                int target = fl ? !xbit : xbit;
                for(auto it = st[target].lower_bound(abs(x - k)); it != end(st[target]); it++) {
                    if(*it > x + k) break;
                    if(n - *it < until) break;
                    int bit = (*it ^ x) & 1;
                    if(del != -1) {
                        st[target].erase(del);
                        del = -1;
                    }
                    q.push(*it);
                    del = *it;
                    if(*it == n) return res;
                }
                if(del != -1) {
                    st[target].erase(del);
                    del = -1;
                }
            }
            res++;
        }
        return -1;
    }
};