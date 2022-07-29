class Solution {
    bool subsetOf(unordered_set<string>& A, unordered_set<string>& B) {
        for(auto& a : A) {
            if(!B.count(a)) return false;
        }
        return true;
    }
public:
    vector<int> peopleIndexes(vector<vector<string>>& A) {
        vector<unordered_set<string>> us;
        for(auto& a : A)
            us.push_back(unordered_set<string>(begin(a),end(a)));
        vector<int> res;
        for(int i = 0; i < A.size(); i++) {
            bool subset = false;
            for(int j = 0; j < A.size() and !subset; j++) {
                if(i == j) continue;
                subset |= subsetOf(us[i], us[j]);
            }
            if(!subset) res.push_back(i);
        }
        return res;
    }
};