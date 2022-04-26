class Solution {
    int solve(vector<pair<int,int>>& q) {
        sort(begin(q), end(q));
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0, res = 0;
        for(int i = 0; i < q.size(); i++) {
            while(!pq.empty() and pq.top() < q[i].first) {
                sum -= 1;
                pq.pop();
            }
            sum += 1;
            pq.push(q[i].second);
            res = max(res, sum);
            if(sum + q.size() - i - 1 < res) break;
        }
        return res;
    }
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> psum(n, nums[0]);
        unordered_map<long long,deque<int>> r,l{{nums[0],{0}}};
        unordered_map<long long, vector<pair<int,int>>> query;
        for(int i = 1; i < n; i++) {
            psum[i] = psum[i-1] + nums[i];
            r[nums[i]].push_back(i);
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            long long lreq = psum.back() - psum[i] - psum[i], rreq = -lreq;
            if(rreq == lreq) res++;
            else {
                if(!r[k-rreq].empty()) {
                    query[k-rreq].push_back({r[k-rreq].front(), r[k-rreq].back()});
                }
                if(!l[k-lreq].empty()) {
                    query[k-lreq].push_back({l[k-lreq].front(), l[k-lreq].back()});
                }
            }
            l[nums[i+1]].push_back(i+1);
            r[nums[i+1]].pop_front();
        }
        
        for(auto& [_, q] : query) {
            res = max(res,solve(q));
        }
        
        return res;
    }
};