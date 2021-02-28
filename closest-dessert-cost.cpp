class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        set<int> toppingCost;
        toppingCost.insert(0);
        for(auto& toppings : toppingCosts) {
            unordered_set<int> topping;
            for(auto& cost : toppingCost) {
                topping.insert(cost + toppings);
                topping.insert(cost + 2 * toppings);
            }

            for(auto& myTopping : topping) {
                toppingCost.insert(myTopping);
            }
        }
        int res = baseCosts[0];
        for(auto& base : baseCosts) {
            int cost = base;
            auto choose = lower_bound(begin(toppingCost), end(toppingCost), target - base);
            if(choose == end(toppingCost)) {
                cost += *prev(choose);
            } else if(choose == begin(toppingCost)){
                cost += *choose;
            } else {
                auto prevChoose = prev(choose);
                if(abs(target - (cost + *prevChoose)) <= abs(target - (cost + *choose))) {
                    cost += *prevChoose;
                } else {
                    cost += *choose;
                }
            }
            if(abs(target - res) > abs(target - cost)){
                res = cost;
            } else if(abs(target - res) == abs(target - cost)) {
                res = min(res, cost);
            }
        }

        return res;
    }
};
