class Solution {
    array<int,3> order(int a, int b, int c) {
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        return {a,b,c};
    }
public:
    int minCost(vector<int>& nums) {
        map<int,int> dp{{nums[0],0}};
        int base = 0;
        if(nums.size() % 2 == 0) {
            base = nums.back(); nums.pop_back();
        }
        for(int i = 1; i < nums.size(); i += 2) {
            map<int,int> dpp;
            auto push = [&](int carry, int val) {
                if(!dpp.count(carry)) dpp[carry] = val;
                else dpp[carry] = min(dpp[carry], val);
            };
            int x = nums[i], y = nums[i+1];
            for(auto& [carry, val] : dp) {
                auto [a,b,c] = order(x,y,carry);
                push(a, val + c);
                push(c, val + b);
            }
            swap(dp,dpp);
        }
        int res = INT_MAX;
        for(auto& [carry, val] : dp) res = min(res, max(carry,base) + val);
        return res;
    }
};