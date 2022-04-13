class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<int>> group;
        vector<bool> merged(accounts.size(), false);
        vector<vector<string>> res;
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                group[accounts[i][j]].insert(i);
            }
        }
        for(int i = 0; i < merged.size(); i++) {
            if(merged[i]) continue;
            merged[i] = true;
            vector<string> mail{accounts[i][0]};
            unordered_set<string> s;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int idx = q.front();
                q.pop();
                for(int i = 1; i < accounts[idx].size(); i++) {
                    s.insert(accounts[idx][i]);
                    for(int ref : group[accounts[idx][i]]) {
                        if(merged[ref]) continue;
                        merged[ref] = true;
                        q.push(ref);
                    }
                }
            }
            mail.insert(end(mail), begin(s), end(s));
            sort(mail.begin() + 1, mail.end());
            res.push_back(mail);
        }
        return res;
    }
};