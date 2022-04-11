class Solution {
    void insertLine(vector<string>& res, vector<string>& picked, int len, int maxWidth) {
        len = len - picked.size();
        int space = maxWidth - len;
        if(picked.size() == 1) {
            res.push_back(picked[0] + string(space, ' '));
            return;
        }
        
            stringstream ss;
        int eachSpace = space / (picked.size() - 1);
        int extraSpace = space % (picked.size() - 1);
        for(int j = 0; j < picked.size(); j++) {
            ss<<picked[j];
            if(j != picked.size() - 1) ss<<string(eachSpace, ' ');
            if(extraSpace) {
                ss<<' ';
                extraSpace--;
            }
        }
        res.push_back(ss.str());
    }
    void insertLastLine(vector<string>& res, vector<string>& picked, int len, int maxWidth) {
        stringstream ss;
        int space = maxWidth - len + 1;
        for(int i = 0; i < picked.size(); i++) {
            ss<<picked[i];
            if(i != picked.size() - 1) ss<<' ';
        }
        ss<<string(space, ' ');
        res.push_back(ss.str());
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> picked, res;
        int len = 0;
        for(int i = 0; i < words.size(); i++) {
            if(len + words[i].size() > maxWidth) {
                insertLine(res, picked, len, maxWidth);
                picked.clear();
                len = 0;
            }
            picked.push_back(words[i]);
            len += words[i].length() + 1;
        }
        
        insertLastLine(res, picked, len, maxWidth);
        return res;
    }
};