class Solution {
    bool isContainLetters(string& start, string& end) {
        if(start.length() != end.length())
            return false;
        map<char, int> m;
        int sz = start.length();
        for(int i = 0; i < sz; i++) {
            m[start[i]]++;
            m[end[i]]--;
        }

        for(auto& letter : m) {
            if(letter.second)
                return false;
        }
        return true;
    }
    string getNextStart(string start, int target, int cur) {
        char status = start[cur];
        while(target != cur) {
            if(status == 'L') {
                if(start[cur - 1] == 'X')
                    swap(start[cur], start[cur - 1]);
                else
                    return "";
            }
            else if(status == 'X') {
                if(start[cur - 1] == 'R') {
                    swap(start[cur], start[cur - 1]);
                }
                else
                    return "";
            }
            cur--;
        }
        return start;
    }
    bool dfs(int pos, string start, string end) {
        if(start == "") return false;
        if(pos == start.length()) return true;
        if(start[pos] == end[pos]) return dfs(pos + 1, start, end);
        for(int i = pos; i < start.length(); i++) {
            if(start[i] == end[pos]) return dfs(pos + 1, getNextStart(start, pos, i), end);
        }
        return false;
    }
public:
    bool canTransform(string start, string end) {
        if(!isContainLetters(start, end)) {
            return false;
        }

        return dfs(0, start, end);
    }
};
