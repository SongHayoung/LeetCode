class Solution {
    vector<string> res;
    string makeString(string& w, int mask) {
        stringstream s;
        int cnt = 0;
        for(int i = w.length() - 1, j = 0; i >= 0; i--, j++) {
            if((1<<i) & mask) {
                cnt++;
            } else {
                if(cnt) s << to_string(cnt);
                s << w[j];
                cnt = 0;
            }
        }
        if(cnt) s << to_string(cnt);
        return s.str();
        
    }
    void backTracking(string& w, int i, int mask) {
        if(w.length() == i) {
            res.push_back(makeString(w,mask));
        } else {
            backTracking(w, i + 1, mask<<1); //select as character
            backTracking(w, i + 1, (mask<<1) + 1); //select as number
        }
    }
public:
    vector<string> generateAbbreviations(string word) {
        backTracking(word,0,0);
        return res;
    }
};