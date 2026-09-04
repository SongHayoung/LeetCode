
class Solution {
    bool helper(vector<int>& A, vector<int>& S, int x) {
        int n = A.size();
        for(int i = 0; i < n; i += x) {
            if(S[i] == S[i+x-1]) {
                for(int j = i; j < i + x; j++) {
                    if(S[j] != A[j]) return false;
                }
            } else {
                int best = 0;
                for(int j = i; j < i + x; j++) {
                    if(A[j] >= A[i + best]) best = j - i;
                }

                while(A[(best + 1) % x + i] == A[best + i]) best = (best + 1) % x + i;
                for(int j = i + x - 1; j >= i; j--, best = (best - 1 + x) % x) {
                    if(A[i + best] != S[j]) return false;
                }
            }
        }
        return true;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> S = nums;
        sort(begin(S), end(S));
        int n = nums.size(), res = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i) continue;
            int j = n / i;
            if(helper(nums,S,i)) res += i;
            if(i != j and helper(nums,S,j)) res += j;
        }
        return res;
    }
};