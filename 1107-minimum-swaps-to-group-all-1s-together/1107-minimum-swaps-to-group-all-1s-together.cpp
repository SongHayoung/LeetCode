class Solution {
public:
    int minSwaps(vector<int>& data) {
        int sum = 0;
        for(int i = 0; i < data.size(); i++) {
            sum += data[i];
            data[i] += (i ? data[i - 1] : 0);
        }
        if(!sum) return 0;
        int res = sum - data[sum - 1];
        for(int i = sum; i < data.size(); i++) {
            res = min(res, sum - data[i] + data[i - sum]);
        }
        return res;
    }
};