class Solution {
public:
    bool isValid(string word) {
        unordered_set<char> v{'a','e','i','o','u','A','E','I','O','U'};
        bool vo = 0, vvo = 0;
        if(word.size() < 3) return false;
        for(auto& ch : word) {
            if(isdigit(ch)) continue;
            if(!isalpha(ch)) return false;
            if(v.count(ch)) vo = true;
            else vvo = true;
        }
        return vo and vvo;
    }
};
