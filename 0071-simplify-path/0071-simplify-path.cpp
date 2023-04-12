class Solution {
    string parse(string path, int& i) {
        stringstream ss;
        while(i < path.length() and path[i] != '/') {
            ss<<path[i++];
        }
        i++;
        return ss.str();
    }
public:
    string simplifyPath(string path) {
        vector<string> st;
        int i = 0;
        while(i < path.length()) {
            string parsed = parse(path, i);
            if(parsed == "" or parsed == ".") continue;
            else if(parsed == "..") {
                if(!st.empty()) st.pop_back();
            } else st.push_back(parsed);
        }
        stringstream ss;
        ss<<"/";
        for(int i = 0; i < st.size(); i++) {
            ss<<st[i];
            if(i != st.size() - 1)
                ss<<"/";
        }
        return ss.str();
    }
};