int cnt[1<<26];
class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
    int bits(string& s) {
        int res = 0;
        for(auto& ch : s) {
            int x = ch - 'a';
            res |= 1<<x;
        }
        return res;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        memset(cnt,0,sizeof cnt);
        for(auto& w : words) {
            int x = bits(w);
            if(w == "asas") cout<<x<<endl;
            cnt[x]++;
        }
        vector<int> res;
        for(auto& p : puzzles) {
            int x = bits(p);
            vector<int> who;
            int sum = 0;
            for(int i = 0; i < 26; i++) if(bit(x,i) and i + 'a' != p[0]) who.push_back(i);
            for(int i = 0; i < 1<<who.size(); i++) {
                int mask = 1<<(p[0]-'a');
                for(int j = 0; j < who.size(); j++) {
                    if(bit(i,j)) continue;
                    mask ^= 1<<who[j];
                }
                sum += cnt[mask];
                
            }
            res.push_back(sum);
        }
        return res;
    }
};