
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream iss(text);
        vector<string> filter;
        string token;
        while (getline(iss, token, ' ')) if (!token.empty()) filter.push_back(token);
        
        for(auto& ch : brokenLetters) {
            vector<string> nfilter;
            for(auto& f : filter) if(!count(f.begin(), f.end(), ch)) nfilter.push_back(f);
            swap(filter, nfilter);
        }
        
        return filter.size();
    }
};