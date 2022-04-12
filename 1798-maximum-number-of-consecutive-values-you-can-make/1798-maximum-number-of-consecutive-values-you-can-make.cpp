class Solution {
public:
    int getMaximumConsecutive(vector<int>& A) {
        sort(begin(A),end(A));
        int ma = 0;
        for(auto& a : A) {
            if(ma + 1 < a) return ma + 1;
            ma += a;
        }
        return ma + 1;
    }
};