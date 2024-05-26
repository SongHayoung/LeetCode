class Solution {
    int check(vector<string>& words, vector<int>& letter, vector<int>& sc, int idx) {
        if(idx >= words.size()) return 0;
        int res1 = check(words, letter, sc, idx + 1), score = 0, possible = 1;
        vector<int> cur(begin(letter), end(letter));
        for(auto& c : words[idx]) {
            if(--cur[c - 'a'] < 0) {
                possible = 0;
                break;
            }
            score += sc[c - 'a'];
        }
        return max(res1, possible ? score + check(words, cur, sc, idx + 1) : 0);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letter(26, 0);
        for(auto& c : letters) { letter[c - 'a']++; }
        return check(words, letter, score, 0);
    }
};