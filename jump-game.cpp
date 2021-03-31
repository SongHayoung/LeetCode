class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> v(nums.size(), false);
        queue<int> q;
        v[0] = true;
        q.push(0);
        while(!q.empty() && !v.back()) {
            int pos = q.front();
            q.pop();
            for(int i = min(pos + nums[pos], (int)nums.size() - 1); i > pos; i--) {
                if(!v[i]) {
                    q.push(i);
                    v[i] = true;
                }
            }
        }
        
        return v.back();
    }
};
