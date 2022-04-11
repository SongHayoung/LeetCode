class Solution {
    int compare(char ch1, char ch2) {
        return (ch1 - ch2 + 26) % 26;
    }
    
    string buildRelativeSequence(string& s) {
        string seq = "";
        for(int i = 0; i < s.length() - 1; i++) {
            seq += to_string(compare(s[i],s[i+1])) + "#";
        }
        return seq;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> seq;
        for(auto str : strings) {
            string sequence = buildRelativeSequence(str);
            seq[sequence].push_back(str);
        }
        vector<vector<string>> res;
        for(auto [_, group] : seq) {
            res.push_back(group);
        }
        return res;
    }
};