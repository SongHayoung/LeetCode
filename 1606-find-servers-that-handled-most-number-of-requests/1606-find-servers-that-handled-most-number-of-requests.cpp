class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k);
        set<int> st;
        for(int i = 0; i < k; i++) st.insert(i);
        priority_queue<pair<long long, long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>> q;
        for(int i = 0; i < arrival.size(); i++) {
            while(q.size() and q.top().first <= arrival[i]) {
                auto [_,who] = q.top(); q.pop();
                st.insert(who);
            }
            if(st.size() == 0) continue;
            int who = i % k;
            auto it = st.lower_bound(who);
            if(it == end(st)) it = begin(st);
            cnt[*it]++;
            q.push({0ll + load[i] + arrival[i], *it});
            st.erase(it);
        }
        int ma = *max_element(begin(cnt), end(cnt));
        vector<int> res;
        for(int i = 0; i < k; i++) if(cnt[i] == ma) res.push_back(i);
        return res;
    }
};