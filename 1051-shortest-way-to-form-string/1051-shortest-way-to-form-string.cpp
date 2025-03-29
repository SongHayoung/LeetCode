class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> seq;
        for(int i = 0; i < source.length(); i++) {
            seq[source[i]].push_back(i);
        }
        int res = 0, mi = -1;
        for(auto& t : target) {
            if(!seq.count(t)) return -1; //not contain character case
            
            auto it = upper_bound(seq[t].begin(), seq[t].end(), mi);
            if(it == seq[t].end()) {
                res++;
                mi = *seq[t].begin();
            } else mi = *it;
        }
        
        return res + (mi >= 0);
    }
};