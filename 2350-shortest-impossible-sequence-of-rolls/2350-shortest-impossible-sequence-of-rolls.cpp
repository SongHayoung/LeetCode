class Solution {
    int fenwick[101010] = {};
    void update(int n, int v) {
        while(n < 101010) {
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
    int shortestSequence(vector<int>& A, int k) {
        vector<int> mp(k+1,1);
        update(1,k);

        for(int i = A.size() - 1; i >= 0; i--) {
            int now = A[i];
            int level = mp[now];
            int sum = query(level - 1);
            
            if(sum) continue;
            
            mp[now] = level + 1;
            update(level,-1);
            update(level  + 1, 1);
        }
        
        return *min_element(begin(mp)+1, end(mp));
    }
};