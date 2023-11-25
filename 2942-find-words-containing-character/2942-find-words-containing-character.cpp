class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i = 0; i < words.size(); i++) {
            bool ok = false;
            for(auto& ch : words[i]) {
                if(ch == x) ok = true;
            }
            if(ok) res.push_back(i);
        }
        return res;
    }
};