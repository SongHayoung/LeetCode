#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        static const int MAXV = 500;
        static const int MAXSUM = MAXV * 2;
        bitset<MAXSUM + 1> pres;
        bitset<MAXSUM + 1> sumPairs;
        for (int i = 0; i < n; ++i) {
            pres.reset();
            sumPairs.reset();
            for (int j = i; j < n; ++j) {
                int x = nums[j];
                if (sumPairs[x]) break;
                auto shifted = pres >> x;
                if ((shifted & pres).any()) break;
                sumPairs |= (pres << x);
                pres.set(x);
                res = max(res, j - i + 1);
            }
        }
        return res;
    }
};