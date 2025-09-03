
class Solution {
public:
    int minOperations(string s, int k) {
        int now = std::count(s.begin(), s.end(), '1');
        int n = s.length();
        if(now == n) return 0;
        if(k % 2 == 0) {
            if((now ^ n) & 1) return -1;
        }
        set<int> st;
        if(k % 2 == 0) {
            for(int i = now & 1; i <= n; i += 2) st.insert(i);
        } else for(int i = 0; i <= n; i++) st.insert(i);
        queue<int> q;
        int res = 1, fl = k & 1;
        q.push(now);
        st.erase(now);
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                int x = q.front(); q.pop();
                vector<int> nxt;
                int until = abs((n - x) - k);
                for(auto it = st.lower_bound(abs(x - k)); it != end(st); it++) {
                    if(*it > x + k) break;
                    if(n - *it < until) break;
                    int bit = (*it ^ x) & 1;
                    if(bit == fl) {
                        nxt.push_back(*it);
                        if(*it == n) return res;
                    }
                }
                while(nxt.size()) {
                    auto now = nxt.back(); nxt.pop_back();
                    st.erase(now);
                    q.push(now);
                }
            }
            res++;
        }
        return -1;
    }
};