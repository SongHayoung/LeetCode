class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> hi;
        priority_queue<int> lo;
        for(auto& n : nums) {
            hi.push(n);
            lo.push(n);
            if(hi.size() > k) hi.pop();
            if(lo.size() > k) lo.pop();
        }
        int res = 0;
        while(hi.size()) {
            res += hi.top();
            hi.pop();
        }
        while(lo.size()) {
            res -= lo.top();
            lo.pop();
        }
        return res;
    }
};