class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        queue<int> q;
        q.push(0);
        while(!q.empty() && !v.back()) {
            int pos = q.front();
            q.pop();
            for(int i = min(pos + nums[pos], (int)nums.size() - 1); i > pos; i--) {
                if(!v[i]) {
                    q.push(i);
                    v[i] = v[pos] + 1;
                }
            }
        }

        return v.back();
    }
};
