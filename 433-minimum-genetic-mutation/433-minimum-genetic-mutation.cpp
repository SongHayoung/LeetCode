class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
        int res = 1;
        char gene[4] = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(start);
        unordered_set<string> vis;
        vis.insert(start);
        unordered_set<string> b(bank.begin(), bank.end());
        if(!b.count(end)) return -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto g = q.front(); q.pop();
                for(int i = 0; i < 8; i++) {
                    auto cp = g;
                    for(int j = 0; j < 4; j++) {
                        cp[i] = gene[j];
                        if(b.count(cp)) {
                            if(cp == end) return res;
                            else if(!vis.count(cp)) {
                                vis.insert(cp);
                                q.push(cp);
                            }
                        }
                    }
                }
            }
            
            res++;
        }
        
        return -1;
    }
};