class WordDistance {
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++) {
            m[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        if(m[word1].size() > m[word2].size()) swap(word1, word2);
        for(auto it = begin(m[word1]); it != end(m[word1]); it++) {
            auto it2 = lower_bound(begin(m[word2]), end(m[word2]), *it);
            if(it2 != end(m[word2]))
                res = min(res, abs(*it - *it2));
            if(it2 != begin(m[word2]))
                res = min(res, abs(*it - *prev(it2)));
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */