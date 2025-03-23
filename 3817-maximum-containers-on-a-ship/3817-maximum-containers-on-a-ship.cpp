class Solution {
public:
    long long maxContainers(long long n, int w, long long maxWeight) {
        long long res1 = maxWeight / w, res2 = 0;
        for(int i = 0; i < n; i++) res2 += n;
        return min(res1,res2);
    }
};
