class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        const char SLASH = '/';
        const char SPACE = ' ';
        for(auto& p : paths) {
            stringstream ss(p);
            string path;
            string file;
            getline(ss, path,  SPACE);
            while(getline(ss, file, SPACE)) {
                m[file.substr(file.find('('))].push_back(path + SLASH + file.substr(0, file.find('(')));
            }
        }
        for(auto& e : m) {
            if(e.second.size() != 1)
                res.push_back(e.second);
        }

        return res;
    }
};