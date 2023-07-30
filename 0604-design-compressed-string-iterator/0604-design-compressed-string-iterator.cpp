class StringIterator {
    deque<pair<char,int>> dq;
public:
    StringIterator(string compressedString) {
        for(int i = 0; i < compressedString.length();) {
            char ch = compressedString[i];
            i += 1;
            int cnt = 0;
            while(i < compressedString.length() and isdigit(compressedString[i])) {
                cnt = cnt * 10 + compressedString[i++] - '0';
            }
            dq.push_back({ch,cnt});
        }
    }

    char next() {
        while(dq.size() and dq.front().second == 0) dq.pop_front();
        if(dq.size()) dq.front().second -= 1;
        return dq.size() ? dq.front().first : ' ';
    }

    bool hasNext() {
        while(dq.size() and dq.front().second == 0) dq.pop_front();
        return dq.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

