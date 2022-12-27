class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> remain(n);
        for(int i = 0; i < n; i++) {
            remain[i] = capacity[i] - rocks[i];
        }
        sort(begin(remain), end(remain));
        int res = 0, i = 0;
        while(i < n and additionalRocks) {
            if(remain[i] == 0) res++;
            else if(remain[i] <= additionalRocks) {
                additionalRocks -= remain[i]; res++;
            } else break;
            i++;
        }
        return res;
    }
};