class Solution {
    unordered_map<char,int> mp;
    unordered_map<int, char> rmp;
    bool helper(vector<string>& w, string& res, int pos, int idx, int carry) {
        if(pos == res.length()) return carry == 0;
        if(idx == w.size()) {
            if(!mp.count(res[pos]) and !rmp.count(carry % 10)) {
                if(carry % 10 == 0 and pos + 1 == res.length()) return false;
                mp[res[pos]] = carry % 10;
                rmp[carry%10] = res[pos];
                
                if(helper(w,res,pos + 1, 0, carry / 10)) return true;
                
                mp.erase(res[pos]);
                rmp.erase(carry%10);
                return false;
            }
            if(mp.count(res[pos]) and mp[res[pos]] == carry % 10) {
                if(pos + 1 == res.length() and mp[res[pos]] == 0) return false;
                return helper(w,res,pos + 1, 0, carry / 10);
            }
            return false;
        }
        
        if(pos >= w[idx].length()) return helper(w,res,pos,idx + 1, carry);
        if(mp.count(w[idx][pos])) {
            if(pos + 1 == w[idx].length() and w[idx].length() > 1 and mp[w[idx][pos]] == 0) return false;
            return helper(w,res,pos,idx + 1, carry + mp[w[idx][pos]]);
        }

        for(int i = 0; i < 10; i++) {
            if(pos + 1 == w[idx].length() and i == 0 and w[idx].length() > 1) continue;
            if(rmp.count(i)) continue;
            mp[w[idx][pos]] = i;
            rmp[i] = w[idx][pos];
            if(helper(w,res,pos,idx+1,carry + i)) return true;
            mp.erase(w[idx][pos]);
            rmp.erase(i);
        }
        return false;
    }
public:
    bool isSolvable(vector<string>& words, string res) {
        for(auto& w : words) {
            if(w.length() > res.length()) return false;
            reverse(begin(w), end(w));
        }
        reverse(begin(res), end(res));
        return helper(words, res, 0, 0, 0);
    }
};