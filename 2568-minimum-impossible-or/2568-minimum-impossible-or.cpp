class Solution {
public:
    int minImpossibleOR(vector<int>& A) {
        unordered_set<int> us(begin(A), end(A));
        for(long long i = 0; ; i++) {
            long long l = 1<<i;
            if(!us.count(l)) return l;
        }
        return -1;
    }
};
