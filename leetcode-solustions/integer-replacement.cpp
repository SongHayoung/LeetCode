class Solution {
public:
    int integerReplacement(int n) {
        map<long, int> v;
        queue<long> q;
        v[n] = 0;
        q.push(n);
        while(!v.count(1)) {
            long num = q.front();
            q.pop();
            if(num & 1) {
                if(!v.count(num + 1)) {
                    v[num + 1] = v[num] + 1;
                    q.push(num + 1);
                }

                if(!v.count(num - 1)) {
                    v[num - 1] = v[num] + 1;
                    q.push(num - 1);
                }
            } else if(!v.count(num>>1)) {
                v[num >> 1] = v[num] + 1;
                q.push(num >> 1);
            }
        }

        return v[1];
    }
};
