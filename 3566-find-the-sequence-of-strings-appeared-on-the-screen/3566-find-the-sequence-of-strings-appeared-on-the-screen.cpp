class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string now = "";
        for(auto& ch : target) {
            now.push_back('#');
            for(char c = 'a'; c <= ch; c++) {
                now.pop_back();
                now.push_back(c);
                res.push_back(now);
            }
        }
        return res;
    }
};