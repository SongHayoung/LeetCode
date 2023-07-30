class Solution {
public:
    string minimumString(string a, string b, string c) {
        string res = string(a.length() + b.length() + c.length() + 1, '#');
        vector<string> ord{a,b,c};
        sort(begin(ord), end(ord));
        do {
            for(int i = 0; i <= ord[0].length(); i++) {
                string now = ord[0].substr(0,i) + ord[1];
                if(now.length() > res.length()) continue;
                if(now.find(ord[0]) == string::npos) continue;
                for(int j = 0; j <= ord[2].length(); j++) {
                    if(now.length() + j > res.size()) continue;
                    string nnow = now + ord[2].substr(ord[2].length() - j, ord[2].length());
                    if(nnow.find(ord[2]) == string::npos) continue;
                    if(nnow.length() == res.length()) res = min(res, nnow);
                    else res = nnow;
                }
            }
        }while(next_permutation(begin(ord), end(ord)));
        return res;
    }
};