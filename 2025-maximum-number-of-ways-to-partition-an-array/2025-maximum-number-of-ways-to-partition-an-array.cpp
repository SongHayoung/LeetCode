class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<long long> psum(n, nums[0]);
        unordered_map<long long,deque<int>> r,l{{nums[0],{0}}};
        vector<int> start(n,0), end(n,0);
        unordered_map<int, int> mp;
        
        for(int i = 1; i < n; i++) {
            psum[i] = psum[i-1] + nums[i];
            r[nums[i]].push_back(i);
        }
        
        for(int i = 0; i < n - 1; i++) {
            long long lreq = psum.back() - 2 * psum[i], rreq = -lreq;
            if(rreq == lreq) res++;
            else {
                if(r.count(k-rreq)) {
                    start[r[k-rreq].front()]++;
                    end[r[k-rreq].back()]--;
                }
                if(l.count(k-lreq)) {
                    start[l[k-lreq].front()]++;
                    end[l[k-lreq].back()]--;
                }
            }
            if(l[nums[i+1]].size() == 2)
                l[nums[i+1]].pop_back();
            
            l[nums[i+1]].push_back(i+1);
            r[nums[i+1]].pop_front();
            
            if(r[nums[i+1]].empty())
                r.erase(nums[i+1]);
        }
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]] += start[i];
            res = max(res, mp[nums[i]]);
            mp[nums[i]] += end[i];
        }
        
        return res;
    }
};