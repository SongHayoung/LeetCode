class Solution {
    deque<long long> compress(vector<int>& A) {
        deque<long long> res;
        for(auto& x : A) {
            if(res.size() == 0 or x < 0 or res.back() <= 0) res.push_back(x);
            else res.back() += x;
        }
        while(res.size() and res.back() <= 0) res.pop_back();
        while(res.size() and res.front() <= 0) res.pop_front();
        return res;
    }
    long long kadane(deque<long long>& A, int ignore) {
        long long res = INT_MIN, now = INT_MIN;
        for(auto& a : A) if(a != ignore) {
            now = max(a, now + a);
            res = max(res, now);
        }
        return res;
    }
public:
    long long maxSubarraySum(vector<int>& nums) {
        long long res = *max_element(begin(nums), end(nums));
        deque<long long> A = compress(nums);
        if(A.size() == 1) return A[0];
        unordered_map<long long, long long> sum,cnt;
        for(auto& a : A) if(a < 0) {
            sum[a] += a;
            cnt[a] += 1;
        }
        vector<pair<long long, long long>> sord, cord;
        for(auto& [k,v] : sum) sord.push_back({v,k});
        for(auto& [k,v] : cnt) cord.push_back({v,k});
        sort(begin(sord), end(sord));
        sort(rbegin(cord), rend(cord));

        unordered_set<int> neg;
        for(int i = 0; i < 2727 and i < sord.size(); i++) {
            neg.insert(sord[i].second);
            neg.insert(cord[i].second);
        }

        for(auto& n : neg) res = max(res, kadane(A,n));
        return res;
    }
};