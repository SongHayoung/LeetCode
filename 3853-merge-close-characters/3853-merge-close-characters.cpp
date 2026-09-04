class Solution {
public:
    string mergeCharacters(string s, int k) {
        string res = "";
        for(auto& ch : s) {
            bool ok = false;
            for(int j = res.length() - 1, op = k; j >= 0 and op > 0 and !ok; op--,j--) {
                if(res[j] == ch) ok = true;
            }
            if(!ok) res.push_back(ch);
        }
        return res;
    }
};