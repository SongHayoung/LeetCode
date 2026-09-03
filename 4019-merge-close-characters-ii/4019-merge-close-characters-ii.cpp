class Solution {
public:
    string mergeCharacters(string s, int k) {
        string res = "";

        for(auto& ch : s) {
            bool ok = false;

            int start = max(0, int(res.length()) - k);

            for(int j = start; j < res.length(); j++) {
                if(res[j] == ch) ok = true;
            }

            if(!ok) res.push_back(ch);
        }

        return res;
    }
};