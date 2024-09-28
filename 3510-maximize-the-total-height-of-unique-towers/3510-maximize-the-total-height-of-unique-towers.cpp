class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(begin(maximumHeight), end(maximumHeight));
        long long res = maximumHeight.back();
        for(int i = maximumHeight.size() - 2; i >= 0; i--) {
            maximumHeight[i] = min(maximumHeight[i], maximumHeight[i+1] - 1);
            if(maximumHeight[i] <= 0) return -1;
            res += maximumHeight[i];
        }
        return res;
    }
};