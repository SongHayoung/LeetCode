class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        vector<int> res(arrival.size(), -1);
        map<int, vector<int>> mp;
        for(int i = 0; i < arrival.size(); i++) mp[arrival[i]].push_back(i);
        priority_queue<int,vector<int>,greater<int>> open, close;
        int st = 1, time = 0;
        mp[INT_MAX] = {};
        for(auto it = begin(mp); it->first != INT_MAX; it++) {
            int nt = next(it)->first;
            time = it->first;
            for(auto idx : it->second) {
                if(state[idx] == 1) close.push(idx);
                else open.push(idx);
            }
            int use = min(nt - time, (int)(open.size() + close.size()));
            while(use) {
                if(open.empty() and close.empty()) break;
                if(st == 1) {
                    if(close.empty()) st = 0;
                    else {
                        res[close.top()] = time++;
                        close.pop();
                        use -= 1;
                    }
                } else if(st == 0) {
                    if(open.empty()) st = 1;
                    else {
                        res[open.top()] = time++;
                        open.pop();
                        use -= 1;
                    }
                }
            }
            if(time != nt) st = 1;
        }
        return res;
    }
};