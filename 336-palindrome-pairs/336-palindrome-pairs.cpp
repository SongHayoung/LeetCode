struct Trie {
    Trie* next[26];
    vector<int> palindromes;
    int eof;
    
    Trie() {
        memset(next,0,sizeof(next));
        eof = -1;
    }
};

class Solution {
    Trie* rvTrie;
    vector<vector<int>> res;
public:
    //o(n) for iterating
    //o(k^2) for palindrome
    //we can caculate palindrome as k(lenth of word)
    //k/2 + (k-1)/2 + (k-2)/2 ... 1/2 = (k) * (k + 1) / 2 / 2 = (k^2 + k)/4 = k^2
    //so total time is o(nk^2)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        rvTrie = new Trie();
        for(int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }
        for(int i = 0; i < words.size(); i++) {
           find(words[i], i);
        }
        
        return res;
    }
    void insert(string& str, int& index) {
        Trie* cur = rvTrie;
        for(int p = str.length() - 1; p >= 0; p--) {
            if(isPalindrome(str, 0, p)) {
                cur->palindromes.push_back(index);
            }
            if(!cur->next[str[p]-'a']) cur->next[str[p]-'a'] = new Trie();
            cur = cur->next[str[p]-'a'];
            
        }
        cur->palindromes.push_back(index);
        cur->eof = index;
    }
    
    void find(string& str, int& idx) {
        Trie* cur = rvTrie;
        for(int i = 0; i < str.length(); i++) {
            if(cur->eof != -1 and cur->eof != idx and isPalindrome(str,i,str.length() - 1)) {
                res.push_back({idx,cur->eof});
            }
            if(!cur->next[str[i]-'a']) return ;
            cur = cur->next[str[i]-'a'];
        }
        for(auto p : cur->palindromes) {
            if(p == idx) continue;
            res.push_back({idx, p});
        }
    }
    
    
    bool isPalindrome(string& str, int l, int r) {
        while(l < r) {
            if(str[l++] != str[r--]) {
                return false;
            }
        }
        return true;
    }
};