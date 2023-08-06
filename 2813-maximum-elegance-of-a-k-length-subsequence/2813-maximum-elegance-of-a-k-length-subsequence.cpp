class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        unordered_map<long long, vector<long long>> mp;
        for(int i = 0; i < items.size(); i++) {
            mp[items[i][1]].push_back(items[i][0]);
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> inc;
        unordered_map<long long, long long> freq;
        priority_queue<pair<long long,long long>> best, cand;
        for(auto& [k,v] : mp) {
            sort(begin(v), end(v));
            best.push({v.back(), k});
        }
        long long res = 0, sum = 0;
        auto push = [&](long long cat, long long val) {
            freq[cat] += 1;
            sum += val;
            inc.push({val,cat});
        };
        while(inc.size() < k) {
            if(best.size()) {
                auto [val,cat] = best.top(); best.pop();
                push(cat,val);
                mp[cat].pop_back();
                for(int i = 0; i < mp[cat].size(); i++) {
                    cand.push({mp[cat][i], cat});
                }
            } else {
                auto [val,cat] = cand.top(); cand.pop();
                push(cat, val);
            }
        }
        while(inc.size() == k) {
            res = max(res, sum + (long long)(freq.size() * freq.size()));
            auto [val, cat] = inc.top(); inc.pop();
            sum -= val;
            if(--freq[cat] == 0) freq.erase(cat);
            while(cand.size() and !freq.count(cand.top().second)) cand.pop();
            if(!cand.size()) break;
            auto [cval, ccat] = cand.top(); cand.pop();
            push(ccat,  cval);
        }
        return res;
    }
};

