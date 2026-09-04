class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        sort(begin(words), end(words));
        vector<vector<string>> res;
        int n = words.size();
        for(int top = 0; top < n; top++) {
            for(int left = 0; left < n; left++) {
                if(top == left) continue;
                for(int right = 0; right < n; right++) {
                    if(top == right or left == right) continue;
                    for(int bottom = 0; bottom < n; bottom++) {
                        if(top == bottom or left == bottom or right == bottom) continue;
                        if(words[top][0] == words[left][0]) {
                            if(words[top][3] == words[right][0]) {
                                if(words[bottom][0] == words[left][3]) {
                                    if(words[bottom][3] == words[right][3]) {
                                        res.push_back({words[top],words[left],words[right],words[bottom]});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};