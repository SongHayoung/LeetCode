class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n = q.size();
        vector<double> r(n);
        for(int i = 0; i < n; i++)
            r[i] = 1.0 * w[i] / q[i];
        //ratio, wage
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> rpq;
        priority_queue<int> wpq;
        for(int i = 0; i < n; i++) {
            rpq.push({r[i], q[i]});
        }
        
        double res = DBL_MAX, rmax = 0;
        int wSum = 0;
        
        while(k--) {
            auto [ratio, w] = rpq.top(); rpq.pop();
            wpq.push(w);
            rmax = ratio;
            wSum += w;
        }
        res = rmax * wSum;
        while(!rpq.empty()) {
            auto [ratio, w] = rpq.top(); rpq.pop();
            rmax = ratio;
            wSum += w;
            wSum -= wpq.top(); wpq.pop();
            wpq.push(w);
            res = min(res, rmax*wSum);
        }
        return res;
    }
};