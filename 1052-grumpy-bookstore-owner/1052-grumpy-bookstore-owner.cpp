class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> cpre(n+1), gpre(n+1);
        for(int i = 0; i < n; i++) {
            cpre[i+1] = cpre[i];
            gpre[i+1] = gpre[i];
            if(grumpy[i]) gpre[i+1] += customers[i];
            else cpre[i+1] += customers[i];
        }
        auto qry = [&](int t) {
            int res = cpre[n];
            res -= gpre[t];
            res += gpre[min(t+minutes,n)];
            return res;
        };
        int res = 0;
        for(int i = 0; i < n; i++) res = max(res, qry(i));
        return res;
    }
};