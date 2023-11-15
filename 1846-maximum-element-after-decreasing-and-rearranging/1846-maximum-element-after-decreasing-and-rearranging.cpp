class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
        sort(begin(A), end(A));
        int res = 1;
        for(auto& a : A) {
            if(a < res) continue;
            else if(a >= res) res += 1;
        }
        
        return res - 1;
    }
};