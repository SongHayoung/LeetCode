struct Trie{
    Trie *next[26];
    int index;
    Trie() : index(-1){
        memset(next,0,sizeof(next));
    }

    void insert(const char *key, int idx){
        if(eof(*key)!=0){
            if(next[*key - 'a']==0)
                next[*key - 'a'] = new Trie();
            next[*key - 'a']->insert(key+1, idx);
        }
        else
            index = idx;
    }

    bool eof(char c){
        return ('a'<=c&&c<='z');
    }
};
class Solution {
    unordered_set<string> w;
    bool visit[12][12]{false,};
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    void dfs(vector<vector<char>>& b, int &n, int &m, vector<string>& w, vector<string>& res, Trie* trie, int y, int x) {
        auto key = b[y][x];
        if(b[y][x] == '#' || !(trie->next[key - 'a'])) return;
        Trie* nxt = trie = trie->next[key - 'a'];
        b[y][x] = '#';
        if(nxt->index != -1) {
            res.push_back(w[nxt->index]);
            nxt->index = -1;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= nx and nx < m and 0 <= ny and ny < n) {
                dfs(b,n,m,w,res,nxt,ny,nx);
            }
        }
        b[y][x] = key;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        Trie* trie = new Trie();
        for(int i = 0; i < words.size(); i++) {
            trie->insert(words[i].c_str(), i);
        }
        vector<string> res;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                dfs(board,n,m,words,res,trie,i,j);
            }

        return res;
    }
};