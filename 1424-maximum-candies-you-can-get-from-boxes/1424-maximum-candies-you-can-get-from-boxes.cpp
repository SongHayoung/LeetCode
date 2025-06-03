class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int res = 0;
        unordered_set<int> close, key, vis;
        queue<int> box;
        
        for(auto& b : initialBoxes) {
            if(status[b] == 1) box.push(b);
            else close.insert(b);
        }
        for(int i = 0; i < status.size(); i++) {
            if(status[i]) key.insert(i);
        }
        while(!box.empty()) {
            int b = box.front(); box.pop();
            if(vis.count(b)) continue;
            vis.insert(b);
            res += candies[b];
            for(auto& k : keys[b]) {
                if(close.count(k)) {
                    if(!vis.count(k))
                        box.push(k);
                } else key.insert(k);
            }
            for(auto& c : containedBoxes[b]) {
                if(key.count(c)) {
                    if(!vis.count(c))
                        box.push(c);
                } else close.insert(c);
            }
        }
        return res;
    }
};