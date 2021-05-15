class Solution {
    void merge(set<set<string>>& mails, string name, vector<vector<string>>& res) {
        for(auto i = begin(mails); i != end(mails); i++) {
            set<string> unions = *i;
            bool isMerged = false;
            do {
                isMerged = false;
                auto j = next(i);
                while (j != end(mails)) {
                    set<string> intersect;
                    set_intersection(begin(unions), end(unions), begin(*j), end(*j), inserter(intersect, intersect.begin()));
                    if (intersect.empty()) { j++; continue; }
                    isMerged = true;
                    unions.insert(begin(*j), end(*j));
                    mails.erase(j++);
                }
            } while(isMerged);
            vector<string> mail{name};
            mail.insert(mail.end(), begin(unions), end(unions));
            res.push_back(mail);
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<set<string>>> sortedAccount;
        vector<vector<string>> res;
        for(auto& acc : accounts) {
            sortedAccount[acc.front()].insert(set<string>(acc.begin() + 1, acc.end()));
        }
        for(auto& e : sortedAccount) {
            merge(e.second, e.first, res);
        }
        return res;
    }
};
