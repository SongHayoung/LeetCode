class Solution {
    unordered_map<char, char> m;
    bool isEqualOperation(string& s) {
        return s[1] == '=';
    }
    char findParent(char ch) { //O(V) max, but after optimize, O(1)
        return m[ch] == ch ? ch : m[ch] = findParent(m[ch]);
    }
    void merge(char a, char b) {
        char pa = findParent(a), pb = findParent(b);
        m[pa] = m[pb] = min(pa, pb);
    }
    bool isSameGroup(char a, char b) {
        return findParent(a) == findParent(b);
    }
    
public:
    bool equationsPossible(vector<string>& equations) { //O(V + E)
        for(char ch = 'a'; ch <= 'z'; ch++) m[ch]=ch;
        vector<pair<char, char>> notEqualPairs;
        for(auto& equation : equations) { //O(E)
            if(isEqualOperation(equation)) {
                merge(equation[0], equation[3]);
            } else {
                notEqualPairs.push_back({equation[0], equation[3]});
            }
        }
        
        for(auto [a, b] : notEqualPairs) { //O(E)
            if(isSameGroup(a,b)) return false;
        }
        return true;
    }
};