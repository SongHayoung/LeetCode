class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> count;
        for(auto ch : s) count[ch]++;
        string ss = "";

        while(!count.empty()) {
            auto it = prev(count.end());
            ss += string(min(repeatLimit, it->second), it->first);
            it->second -= min(repeatLimit, it->second);
            if(it == count.begin()) break;
            auto nxt = prev(it);
            
            if(it->second == 0) {
                count.erase(it);
            } else {
                ss += nxt->first;
                nxt->second -= 1;
                if(nxt->second == 0)
                    count.erase(nxt);
            }
        }

        return ss;
    }
};