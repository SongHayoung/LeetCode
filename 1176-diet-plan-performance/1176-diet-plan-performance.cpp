class Solution {
public:
    int dietPlanPerformance(vector<int>& A, int k, int lower, int upper) {
        long long sum = accumulate(begin(A), begin(A) + k, 0ll), res = 0;
        for(int i = k; i < A.size(); i++) {
            if(sum < lower) res--;
            if(sum > upper) res++;
            sum = sum + A[i] - A[i-k];
        }
        if(sum < lower) res--;
        if(sum > upper) res++;
        return res;
    }
};