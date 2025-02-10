class Solution {
public:
    string clearDigits(string s) {
        string res = "";
        for(auto& ch : s) {
            if(isdigit(ch)) {
                if(res.size()) res.pop_back();
            } else res.push_back(ch);
        }
        return res;
    }
};
