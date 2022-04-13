class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        unordered_map<int, string> partial;
        vector<int> res;
        int part = 0;
        bool flag = true;
        string replaceStr(stamp.size(), '?');
        for(int sz = stamp.size(); sz; sz--) {
            for(int i = 0; i <= stamp.size() - sz; i++) {
                partial[part++] = string(i, '?') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '?');
            }
        }
        while(flag) {
            flag = false;
            for(int i = 0; i < part; i++) {
                auto pos = target.find(partial[i]);
                while(pos != std::string::npos) {
                    flag = true;
                    res.push_back(pos);
                    target.replace(pos, stamp.length(), replaceStr);
                    cout<<target<<endl;
                    pos = target.find(partial[i], pos + 1);
                }
            }
        }
        for(int i = 0; i < target.length(); i++)
            if(target[i] != '?')
                return vector<int>();
        reverse(res.begin(), res.end());
        return res;
    }
};