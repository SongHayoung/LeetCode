class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        array<int,3> dp1{A[0],B[0],0}, dp2{B[0],A[0],1};
        auto operation = [](array<int,3>& dp, array<int,3>& dpp, int op) {
            if(dp[0] < dpp[0] and dp[1] < dpp[1]) {
                dpp[2] = min(dpp[2], dp[2] + op);
            }
        };
        for(int i = 1; i < A.size(); i++) {
            array<int,3> dpp1{A[i],B[i],INT_MAX - 10};
            array<int,3> dpp2{B[i],A[i],INT_MAX - 10};
            operation(dp1,dpp1,0);
            operation(dp2,dpp1,0);
            operation(dp1,dpp2,1);
            operation(dp2,dpp2,1);
            swap(dp1,dpp1);
            swap(dp2,dpp2);
        }
        return min(dp1[2], dp2[2]);
    }
};