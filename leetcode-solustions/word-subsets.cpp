class Solution {
    bool chk(unordered_map<char, int>& a, unordered_map<char,int>& b) {
        for(auto entity : b) {
            if(a[entity.first] < entity.second)
                return false;
        }

        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int bsz = B.size();
        vector<string> res;
        unordered_map<char, int> bMap;
        for(int i = 0; i < bsz; i++) {
            unordered_map<char,int> m;
            for(int j = 0; j < B[i].length(); j++)
                m[B[i][j]]++;
            for(auto entity : m) {
                bMap[entity.first] = max(bMap[entity.first], entity.second);
            }
        }

        for(string& a : A) {
            unordered_map<char,int> m;
            for(int i = 0; i < a.length(); i++)
                m[a[i]]++;
            if(chk(m, bMap))
                res.push_back(a);
        }

        return res;
    }
};
