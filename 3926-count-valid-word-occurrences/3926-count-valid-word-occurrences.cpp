class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        unordered_map<string,int> freq;
        for(auto& chunk : chunks) {
            for(auto& ch :  chunk) {
                if(isalpha(ch)) s.push_back(ch);
                else if(ch == '-') {
                    if(s == "") continue;
                    if(s.back() == '-') {
                        s.pop_back();
                        freq[s]++;
                        s = "";
                    } else s.push_back(ch);
                }
                else {
                  
        if(s != "") {
            if(s.back() == '-') s.pop_back();
            freq[s]++;
            s = "";
        }
                }
            }
        }
        if(s != "") {
            if(s.back() == '-') s.pop_back();
            freq[s]++;
            s = "";
        }
        vector<int> res;
        for(auto& q : queries) res.push_back(freq[q]);
        return res;
    }
};