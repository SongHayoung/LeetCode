class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> q;
        for(auto n : nums) q.push(n);
        while(k) {
            if(q.top() == 1) return res + k;
            else {
                k -= 1;
                long long tp = q.top(); q.pop();
                res += tp;
                q.push((tp + 2) / 3);
            }
        }
        return res;
    }
};