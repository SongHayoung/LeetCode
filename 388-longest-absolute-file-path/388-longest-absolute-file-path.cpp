class Solution {
    pair<int, string> parse(string& input, int& i) {
        int depth = 0;
        stringstream ss;
        while(input[i] == '\t') {
            i += 1;
            depth++;
        }
        while(i < input.length() and input[i] != '\n') {
            ss<<input[i++];
        }
        i += 1;

        return {depth, ss.str()};
    }
    bool isFile(string& path) {
        return path.find('.') != string::npos;
    }
public:
    int lengthLongestPath(string input) {
        vector<int> st;
        int res = 0, i = 0;
        while(i < input.length()) {
            auto [depth, path] = parse(input, i);
            while(st.size() > depth) st.pop_back();
            st.push_back((st.empty() ? 0 : st.back()) + path.length());
            if(isFile(path)) {
                res = max(res, st.back() + (int)st.size() - 1);
            }
        }
        return res;
    }
};