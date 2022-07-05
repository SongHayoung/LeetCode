class Solution {
    double helper(vector<int> A, long long count) {
        int find1 = (count+1) / 2, find2 = count & 1 ? find1 : find1 + 1;
        int median1 = 0, median2 = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < find1) find1-=A[i];
            else if(find1) {
                find1 = 0;
                median1 = i;
            }
            if(A[i] < find2) find2-=A[i];
            else if(find2) {
                find2 = 0;
                median2 = i;
            }
        }
        return (median1 + median2) / 2.0;
    }
public:
    vector<double> sampleStats(vector<int>& A) {
        double mi = DBL_MAX, ma = DBL_MIN, mode = 0, n = A.size();
        long long sum = 0, count = 0;
        for(int i = 0; i < n; i++) {
            if(!A[i]) continue;
            mi = min(mi, 1.0*i);
            ma = max(ma, 1.0*i);
            sum += 1ll * i * A[i];
            count += A[i];
            if(A[mode] < A[i]) mode = i;
        }
        double avg = 1.0 * sum / count;
        double median = helper(A, count);
        return {mi,ma,avg,median,mode};
    }
};