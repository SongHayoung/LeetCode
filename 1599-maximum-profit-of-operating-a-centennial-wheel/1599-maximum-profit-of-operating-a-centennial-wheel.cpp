class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0, ma = 0, res = -1, wait = 0, rotate = 1;
        for(auto& c : customers) {
            wait += c;
            int board = min(wait,4);
            profit += board*boardingCost - runningCost;
            wait -= board;
            if(profit > ma) {
                ma = profit;
                res = rotate;
            }
            rotate++;
        }
        while(wait) {
            int board = min(wait,4);
            profit += board*boardingCost - runningCost;
            wait -= board;
            if(profit > ma) {
                ma = profit;
                res = rotate;
            }
            rotate++;
        }
        return res;
    }
};