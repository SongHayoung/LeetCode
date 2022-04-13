class Solution {
    double arrviveTime(int target, int cur, int speed) {
        return (target - cur) * 1.0 / speed;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> order;
        for(int i = 0; i < speed.size(); i++) {//o(n)
            order.push_back({position[i], speed[i]});
        }
        sort(order.begin(), order.end()); //o(nlogn);
        
        double dp = arrviveTime(target, order.back().first, order.back().second);
        int res = 1;
        for(int i = position.size() - 2; i >= 0; i--) {
            double arvTime = arrviveTime(target, order[i].first, order[i].second);
            if(arvTime > dp) {
                dp = arvTime;
                res++;
            }
        }
                
        return res;
    }
};