class Solution {
    const string target = "123450";
    // 0 1 2
    // 3 4 5
    vector<vector<int>> edge {{1,3}, //0
                              {0,2,4}, //1
                              {1, 5}, //2
                              {0, 4}, //3
                              {1,3,5}, //4
                              {2,4}}; //5
    int findZero(string& str) {
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '0') return i;
        }
        return -1;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string b = "";
        for(auto row : board) {
            for(auto col : row) {
                b += (col + '0');
            }
        }
        if(b == target) return 0;
        queue<pair<string, int>> q;
        q.push({b, findZero(b)});
        unordered_set<string> v;
        v.insert(b);
        int res = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [status, zero] = q.front(); q.pop();
                for(auto near : edge[zero]) {
                    string next = status;
                    swap(next[near], next[zero]);
                    if(!v.count(next)) {
                        v.insert(next);
                        q.push({next, near});
                        if(next == target) return res;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};