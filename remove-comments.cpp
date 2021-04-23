class Solution {
public:
    vector<string> removeComments(vector<string>& s) {
        vector<string> ans;
        bool inBlock = false;
        stringstream ss;
        for (auto &t:s) {
            for (int i = 0; i < t.size();) {
                if (!inBlock) {
                    if (i + 1 == t.size()) ss << t[i++];
                    else {
                        string m = t.substr(i,2);
                        if (m == "/*") inBlock ^= true, i+=2;
                        else if (m == "//") break;
                        else ss << t[i++];
                    }
                }
                else {
                    if (i + 1 == t.size()) i++;
                    else {
                        string m = t.substr(i,2);
                        if (m == "*/") inBlock ^= true, i+=2;
                        else i++;
                    }
                }
            }
            if (ss.str().length() && !inBlock) ans.push_back(ss.str()), ss.str("");
        }
        return ans;
    }
};
