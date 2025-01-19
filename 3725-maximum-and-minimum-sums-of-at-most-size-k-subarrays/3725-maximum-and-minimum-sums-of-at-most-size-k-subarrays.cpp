class Solution {
public:
    long long minMaxSubarraySum(vector<int>& A, long long k) {
        long long n = A.size(), res = 0;
        deque<array<long long, 3>> mi,ma;
        long long miSum = 0, maSum = 0;
        for(int i = 0; i < n; i++) {
            long long micover = i, macover = i;
            while(mi.size() and mi[0][0] <= i - k) miSum -= mi[0][2], mi.pop_front();
            while(ma.size() and ma[0][0] <= i - k) maSum -= ma[0][2], ma.pop_front();
            if(mi.size() and mi[0][1] == i - k) {
                miSum -= mi[0][2]; mi[0][1] += 1;
            }
            if(ma.size() and ma[0][1] == i - k) {
                maSum -= ma[0][2]; ma[0][1] += 1;
            }
            while(mi.size() and mi.back()[2] >= A[i]) {
                micover = mi.back()[1];
                miSum -= (mi.back()[0] - mi.back()[1] + 1) * mi.back()[2];
                
                mi.pop_back();
            }
            while(ma.size() and ma.back()[2] <= A[i]) {
                macover = ma.back()[1];
                maSum -= (ma.back()[0] - ma.back()[1] + 1) * ma.back()[2];
                ma.pop_back();
            }
            ma.push_back({i,macover,A[i]});
            mi.push_back({i,micover,A[i]});
            micover = max(micover, i - k + 1);
            macover = max(macover, i - k + 1);
            miSum += (i - micover + 1) * A[i];
            maSum += (i - macover + 1) * A[i];
            res += miSum + maSum;
        }
        return res;
        
    }
};