class Solution {
    string parse(string& s, int& p) {
        int n = s.length();
        string res = "";
        while(p < n and s[p] != ' ') {
            res.push_back(s[p++]);
        }
        p++;
        return res;
    }
    unordered_set<string> helper(string s) {
        int p = 0, n = s.length();
        unordered_set<string> res;
        while(p < n) {
            string token = parse(s, p);
            res.insert(token);
        }
        return res;
    }
public:
    vector<string> sortFeatures(vector<string>& A, vector<string>& R) {
        unordered_map<string, int> idmp;
        unordered_map<string, int> freq;
        for(int i = 0; i < A.size(); i++) {
            idmp[A[i]] = i;
            freq[A[i]] = 0;
        }
        for(auto& r : R) {
            for(auto& f : helper(r)) {
                if(idmp.count(f))
                    freq[f]++;
            }
        }
        vector<pair<int, int>> S;
        for(auto& a : A) {
            S.push_back({freq[a], idmp[a]});
        }
        
        sort(begin(S), end(S), [](auto& a, auto& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        
        vector<string> res;
        
        for(auto& [_, idx] : S) {
            res.push_back(A[idx]);
        }
        
        return res;
    }
};