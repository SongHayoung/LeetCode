class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int res = queries.size();
        vector<int> pre(nums.size() + 1);
        sort(rbegin(queries), rend(queries));
        priority_queue<int> q;
        for(int i = 0; i < nums.size(); i++) {
            while(queries.size() and queries.back()[0] <= i) {
                q.push(queries.back()[1]);
                queries.pop_back();
            }
            if(i) pre[i] += pre[i-1];
            while(nums[i] > pre[i]) {
                if(q.size() == 0 or q.top() < i) return -1;
                pre[i]++;
                pre[q.top() + 1]--;
                res--;
                q.pop();
            }
        }
        return res;
    }
};