class Solution {
public:
    int getMaximumConsecutive(vector<int>& A) {
        sort(rbegin(A), rend(A));
        int res = 0;
        while(A.size()) {
            if(A.back() <= res + 1) {
                res += A.back();
                A.pop_back();
            } else break;
        }
        return res + 1;
    }
};