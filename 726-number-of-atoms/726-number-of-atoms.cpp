class Solution {
    bool isLowercase(char ch) {
        return ('a' <= ch and ch <= 'z');
    }
    
    bool isUppercase(char ch) {
        return 'A' <= ch and ch <= 'Z';
    }
    
    string serializeAtom(string formula, int &i) {
        stringstream ss;
        while(i < formula.length() and isLowercase(formula[i])) {
            ss<<formula[i++];
        }
        return ss.str();
    }

    int serializeCnt(string formula, int &i) {
        int res = 0;
        while(i < formula.length() and isdigit(formula[i])) {
            res = res * 10 + (formula[i++] & 0b1111);
        }
        return res;
    }
    
    unordered_map<string, int> serialize(string formula, int &i) {
        unordered_map<string, int> res;
        while(i < formula.length() and formula[i] != ')') {
            if(isUppercase(formula[i])) {
                string atom = formula[i] + serializeAtom(formula, ++i);
                int count = i < formula.length() and isdigit(formula[i]) ? serializeCnt(formula, i) : 1;
                res[atom] += count;
            } else if(formula[i] == '(') {
                unordered_map<string, int> innerResult = serialize(formula, ++i);
                int multiply = i < formula.length() and isdigit(formula[i]) ? serializeCnt(formula, i) : 1;
                for(auto [atom, count] : innerResult) {
                    res[atom] += count * multiply;
                }
            }
        }
        i++;
        return res;
    }
public:
    string countOfAtoms(string formula) {
        int i = 0;
        unordered_map<string, int> atoms = serialize(formula, i);
        map<string, int> sortedAtom(atoms.begin(), atoms.end());
        stringstream ss;
        for(auto [atom, count]: sortedAtom) {
            ss<<atom;
            if(count > 1) ss<<to_string(count);
        }
        return ss.str();
    }
};