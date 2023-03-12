class Solution {
    long long fenwick[2020];
    long long bit[2020];
    void update(long long n) {
        bit[n] = 1;
        while(n < 2020) {
            fenwick[n] += 1;
            n += n & - n;
        }
    }
    long long query(long long n) {
        long long res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
    long long ask(long long l, long long r) {
        return query(r) - query(l-1);
    }
public:
    int findMinimumTime(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        memset(fenwick, 0, sizeof fenwick);
        memset(bit, 0, sizeof bit);
        priority_queue<array<int,3>> q;
        int l = 0, r = 0, n = A.size();
        auto work = [&](int x) {
            if(q.size() and -q.top()[0] <= x) {
                int time = q.top()[1], fin = -q.top()[0], start = q.top()[2];
                time -= ask(start,fin);
                if(time > 0) {
                    for(int i = fin; i >= start and time; i--) {
                        if(!bit[i]) {
                            update(i);
                            time -= 1;
                        }
                    }
                }
                q.pop();
            }
        };
        while(r < n) {
            int time = A[r][0];
            while(q.size() and -q.top()[0] < time) {
                work(-q.top()[0]);
            }
            while(r < n and A[r][0] == time) {
                q.push({-A[r][1], A[r][2], A[r][0]});
                r += 1;
            }
            if(q.size() and -q.top()[0] == time) work(time);
        }
        while(q.size()) {
            work(-q.top()[0]);
        }
        return query(2000);
    }
};