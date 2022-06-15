class Solution {
    int fenwick[100000];
    void update(int n, int v) {
        while(n < 100000) {
            fenwick[n] += v;
            n += n & -n;
        }
    }
    int query(int n) {
        int res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
public:
    string minInteger(string num, int k) {
        string res = "";
        unordered_map<char, queue<int>> q;
        int n = num.length();
        for(int i = 0; i < n; i++)
            q[num[i]].push(i);
        for(int i = 0; i < n; i++) {
            for(char j = '0'; j <= '9'; j++) {
                if(q[j].empty()) continue;
                int now = q[j].front();
                int real = now + query(n) - query(now + 1);
                if(real <= i + k) {
                    k -= (real - i);
                    q[j].pop();
                    res.push_back(j);
                    update(now + 1, 1);
                    break;
                }
            }
        }
        
        return res;
    }
};