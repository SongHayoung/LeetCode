class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> us;
        for(auto& w : words) {
            string code = "";
            for(auto& ch : w) {
                code += morse[ch-'a'];
            }
            us.insert(code);
        }
        return us.size();
    }
};