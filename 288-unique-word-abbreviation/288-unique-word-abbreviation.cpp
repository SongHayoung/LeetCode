class ValidWordAbbr {
private:
    unordered_map<string, set<string>> words;

private:
    string getAbbreviation(string word) {
        return word.length() <= 2 ? word : word[0] + to_string(word.length() - 2) + word[word.length() - 1];
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(string word : dictionary) {
            string abbreviation = getAbbreviation(word);
            auto it = words.find(abbreviation);
            if(it == words.end()) {
                words.insert(make_pair(abbreviation, set<string> {word}));
            } else {
                it->second.insert(word);
            }
        }
    }

    bool isUnique(string word) {
        auto it = words.find(getAbbreviation(word));
        return it == words.end() || (*(it->second.begin()) == word && it->second.size() == 1);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */