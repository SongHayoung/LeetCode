class Solution {
    unordered_map<char, set<char>> to;
    unordered_map<char, int> from;

    pair<char, char> compare(string& s1, string& s2) {
        for(int i = 0; i < min(s1.length(), s2.length()); i++) {
            if(s1[i] == s2[i]) continue;
            return {s1[i], s2[i]};
        }
        return {'_','_'};
    }

    void insert(char be, char af) {
        if(to[be].count(af) || be == '_') return;
        to[be].insert(af);
        from[af]++;
        from[be] += 0;
    }

public:
    string alienOrder(vector<string>& words) {
        for(int i = 0; i <words.size() - 1; i++) {
            auto [before, after] = compare(words[i], words[i + 1]);
            if(before == '_' and words[i].length() > words[i+1].length()) return"";
            insert(before, after);
            
        }
        
        for(auto w : words) 
            for(auto ch : w)
                from[ch] += 0;
        
        
        string res = "";
        queue<char> q;
        for(auto [ch, v]: from) {
            if(!v) q.push(ch);
        }
        
        while(!q.empty()) {
            auto ch = q.front(); q.pop();
            res += ch;
            for(auto nxt : to[ch]) {
                if(--from[nxt] == 0) q.push(nxt);
            }
        }

        return res.length() == from.size() ? res : "";
    }
};