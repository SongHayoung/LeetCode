class Solution {
    unordered_map<char, vector<int>> seq;
    bool twoPointerCompare(string& origin, string& target) {//o(min(target.len, origin.len))
        int j = 0;
        for(int i = 0; i < origin.length() and j < target.length(); i++) {
            if(origin[i] == target[j])
                j++;
        }
        
        return target.length() == j;
    }
    
    bool binarySearchCompare(string& target) { //o(mlogn) is maximum and extra space o(n)
        int mi = -1;
        for(int i = 0; i < target.length(); i++) {
            if(!seq.count(target[i])) return false; //early return

            auto it = upper_bound(seq[target[i]].begin(), seq[target[i]].end(), mi);
            if(it == seq[target[i]].end()) return false; //no match
            
            mi = *it; //update    
        }
        return true;
    }
    
    void seqMap(string& s) {
        for(int i = 0; i < s.length(); i++) {
            seq[s[i]].push_back(i);
        }
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        sort(dictionary.begin(), dictionary.end(), [](string& s1, string& s2){ //o(mlogm)
           if(s1.length() == s2.length()) return s1 < s2;
            return s1.length() > s2.length();
        });
        
        seqMap(s);
        
        for(auto& dict: dictionary) {
            if(binarySearchCompare(dict))
                return dict;
        }
        
        
        return res;
    }
};