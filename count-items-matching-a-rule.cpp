class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int pos = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2, res = 0;
        for(auto& item : items) {
            if(item[pos] == ruleValue)
                res++;
        }
        return res;
    }
};
