class Solution {
    bool isIncluded(map<char, int>& chars, const map<char, int>& mustIncluded, char exclude) {
        for(auto entity : mustIncluded) {
            if(entity.second > chars[entity.first] + (entity.first == exclude ? -1 : 0))
                return false;
        }
        return true;
    }
public:
    int balancedString(string s) {
        int limit = s.length() / 4;
        map<char, int> m {{'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}};
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        map<char, int> nonBalanced;
        for(auto entity : m)
            if(entity.second > limit)
                nonBalanced.insert({entity.first, entity.second - limit});

        if(nonBalanced.empty())
            return 0;
        
        int res = s.length();
        int start = 0, end = s.length() - 1;
        bool isBackward = false;
        
        while(true) {
            if(!isBackward) {
                if(isIncluded(m, nonBalanced, s[start])) {
                    m[s[start]]--;
                    start++;
                    res = min(res, end - start + 1);
                } else {
                    isBackward = true;
                }
            } else {
                if(isIncluded(m, nonBalanced, s[end])) {
                    m[s[end]]--;
                    end--;
                    res = min(res, end - start + 1);
                } else if(!start) {
                    return res;
                } else {
                    m[s[start - 1]]++;
                    start--;
                }
            }
        }
        return res;
    }
};
