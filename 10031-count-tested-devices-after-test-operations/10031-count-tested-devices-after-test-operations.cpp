class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0, pre = 0;
        for(auto& x : batteryPercentages) {
            x -= pre;
            if(x > 0) {
                res += 1;
                pre += 1;
            }
        }
        return res;
    }
};