class Solution {
    unordered_set<string> allowCategories{"restaurant", "grocery", "pharmacy", "electronics"};
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> res;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < code.size(); i++) {
            if(!isActive[i]) continue;
            if(!allowCategories.count(businessLine[i])) continue;
            if(code[i] == "") continue;
            bool ok = true;
            for(auto& ch : code[i]) {
                if(isalpha(ch)) continue;
                if(isdigit(ch)) continue;
                if(ch == '_') continue;
                ok = false;
                break;
            }
            if(ok) {
                mp[businessLine[i]].push_back(code[i]);
            }
        }
        for(auto& k : {"electronics", "grocery", "pharmacy", "restaurant"}) {
            sort(begin(mp[k]), end(mp[k]));
            for(auto& s : mp[k]) res.push_back(s);
        }
        return res;
    }
};