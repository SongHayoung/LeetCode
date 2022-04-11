class Solution {
    string subStringWhiteSpace(string s, int &pos, int start) {
        int end = -1;
        bool flag = true;
        for(; pos >= start; pos--) {
            if(s[pos] == ' ' && flag) continue;
            if(s[pos] == ' ' && !flag) break;
            if(end == -1) end = pos;
            flag = false;
        }

        return s.substr(pos + 1, end - pos);
    }
    queue<string> reversedStringRemovedWitheSpace(string s) {
        queue<string> q;
        int pos = s.length() - 1, start;
        for(start = 0; start < s.length() && s[start] == ' '; start++);

        while(pos >= start) {
            q.push(subStringWhiteSpace(s, pos, start));
        }

        return q;
    }
public:
    string reverseWords(string s) {
        queue<string> q = reversedStringRemovedWitheSpace(s);

        stringstream solution;

        while(!q.empty()) {
            solution<<q.front();
            q.pop();
            if(!q.empty())
                solution<<' ';
        }

        return solution.str();
    }
};