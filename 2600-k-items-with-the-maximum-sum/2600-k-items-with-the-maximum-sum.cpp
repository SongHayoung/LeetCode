class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int x = min(numOnes, k);
        int res = x;
        k -= x;
        numOnes -= x;
        x = min(numZeros, k);
        k -= x;
        x = min(numNegOnes, k);
        res -= x;
        return res;
    }
};