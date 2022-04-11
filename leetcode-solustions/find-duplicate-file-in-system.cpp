class Solution {
    vector<string> split(string& s) {
        stringstream ss(s);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> res(begin, end);
        copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
        return res;
    }
    unordered_map<string, vector<string>> sort(string& s) {
        vector<string> str = split(s);
        string path = str.front() + "/";
        unordered_map<string, vector<string>> res;
        for(int i = 1; i < str.size(); i++) {
            auto p = divide(str[i]);
            res[p.first].push_back(path+p.second);
        }

        return res;
    }
    pair<string, string> divide(string& s) {
        int pos = s.find('(');
        string innerText = s.substr(pos);
        string file = s.substr(0, pos);
        return {innerText, file};
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for(auto& p : paths) {
            unordered_map<string, vector<string>> res = sort(p);
            for(auto& e : res) {
                m[e.first].insert(m[e.first].end(), begin(e.second), end(e.second));
            }
        }
        vector<vector<string>> res;
        for(auto& e : m) {
            if(e.second.size() != 1)
                res.push_back(e.second);
        }

        return res;
    }
};
