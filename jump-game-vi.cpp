class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<long> v(sz, INT_MIN);
        v[sz - 1] = nums[sz - 1];
        queue<pair<int, long>> q;
        q.push({sz - 1, v[sz - 1]});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.second < v[p.first])
                continue;
            pair<int, int> small{sz, INT_MIN}, far{sz, INT_MIN};
            bool flag = true;
            for(int i = p.first - 1; i >= max(0, p.first - k); i--) {
                if(nums[i] >= 0 && v[p.first] + nums[i] > v[i]) {
                    v[i] = v[p.first] + nums[i];
                    q.push({i, v[i]});
                    flag = false;
                    break;
                }
                if(nums[i] < 0 && v[p.first] + nums[i] > v[i]) {
                    if(small.first == 0) {
                        small.first = i;
                        small.second = v[p.first] + nums[i];
                    } else {
                        if(small.second <= v[p.first] + nums[i]) {
                            small.first = i;
                            small.second = v[p.first] + nums[i];
                        }
                    }

                    far.first = i;
                    far.second = v[p.first] + nums[i];
                }
            }
            if(flag && small.first != sz) {
                q.push(small);
                v[small.first] = small.second;
                if(far.first != small.first) {
                    q.push(far);
                    v[far.first] = far.second;
                }
            }
        }

        return v.front();
    }
};
