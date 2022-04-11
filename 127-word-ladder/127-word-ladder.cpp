class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        unordered_set<string> w(words.begin(), words.end()), beginQ, endQ, *pBeginQ, *pEndQ;
        if(!w.count(endWord)) return 0;
        beginQ.insert(beginWord);
        endQ.insert(endWord);

        int res = 2;
        while(!beginQ.empty() and !endQ.empty()) {
            if(beginQ.size() <= endQ.size()) {
                pBeginQ = &beginQ;
                pEndQ = &endQ;
            } else {
                pBeginQ = &endQ;
                pEndQ = &beginQ;
            }
            unordered_set<string> tmpQ;
            for(auto& str : *pBeginQ) {
                for(int i = 0; i < str.length(); i++) {
                    string tmp = str;
                    for(int j = 0; j < 26; j++) {
                        tmp[i] = j + 'a';
                        if(pEndQ->count(tmp)) return res;
                        if(w.count(tmp)) {
                            w.erase(tmp);
                            tmpQ.insert(tmp);
                        }
                    }
                }
            }
            tmpQ.swap(*pBeginQ);
            res++;
        }
        return 0;
    }
};