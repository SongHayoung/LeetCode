class Solution {
    vector<unordered_set<int>> groupOrder;
    vector<int> groupOrderCounter;
    vector<vector<int>> groupping;
        
    vector<int> unGroupCounter;
    
    vector<vector<int>> beforeItemsOrder;
    vector<int> beforeItemsCounter;
    
    unordered_set<int> unGroup;
    unordered_set<int> unUsed;
    unordered_set<int> unUsedGroup;
    
    vector<int> res;
    
    void initGroupMembers(vector<int>& group) {
        for(int i = 0; i < group.size(); i++) {
            unUsed.insert(i);
            if(group[i] == -1) {
                unGroup.insert(i);
            } else {
                groupping[group[i]].push_back(i);
            }
        }
    }
    
    void initGroupOrder(vector<int>& group, vector<vector<int>>& beforeItems, int n) {
        for(int i = 0; i < n; i++) {
            int selfGroup = group[i];
            for(auto before : beforeItems[i]) {
                int beforeGroup = group[before];
                if(selfGroup != -1) {
                    if(beforeGroup != -1) {
                        if(beforeGroup != selfGroup and groupOrder[beforeGroup].insert(selfGroup).second) {
                            groupOrderCounter[selfGroup]++;
                        }
                    } else {
                        unGroupCounter[selfGroup]++;
                    }
                }
                beforeItemsOrder[before].push_back(i);
                beforeItemsCounter[i]++;
            }
        }
    }
    
    void pushUnGroupItems(vector<int>& group) {
        for(auto un : unGroup) { //select -1 group
            if(beforeItemsCounter[un] == 0) {
                res.push_back(un);
                for(auto after : beforeItemsOrder[un]) {
                    beforeItemsCounter[after]--;
                    if(group[after] != -1) {
                        unGroupCounter[group[after]]--;
                    }
                }
            }
        }
    }
    
    void sortingGroupItems(vector<int>& group, int groupId) {
        queue<int> q;
        for(auto member : groupping[groupId]) {
            if(beforeItemsCounter[member] == 0)
                q.push(member);
        }
                    
        while(!q.empty()) {
            auto member = q.front(); q.pop();
            res.push_back(member);
            for(auto after : beforeItemsOrder[member]) {
                if(--beforeItemsCounter[after] == 0 and group[after] == groupId) {
                    q.push(after);
                }
            }
        }   
                    
        for(auto after : groupOrder[groupId]) {
            groupOrderCounter[after]--;
        }
    }
    
    void eraseUsedGroupAndItems(vector<int>& group, int from) {
        for(int i = from; i < res.size(); i++) {
            unUsed.erase(res[i]);
            if(group[res[i]] != -1) {
                unUsedGroup.erase(group[res[i]]);
            } else {
                unGroup.erase(res[i]);
            }
        }
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        groupping = vector<vector<int>>(m);
        
        groupOrder = vector<unordered_set<int>>(m);
        groupOrderCounter = vector<int>(m);
        unGroupCounter = vector<int>(m);
        
        beforeItemsOrder = vector<vector<int>>(n);
        beforeItemsCounter = vector<int>(n);
        
        for(int i = 0; i < m; i++) unUsedGroup.insert(i);
        
        initGroupMembers(group);
        initGroupOrder(group, beforeItems, n);
        
        while(!unUsed.empty()) {
            int beforeSize = res.size();
            
            pushUnGroupItems(group);
            
            for(auto gr : unUsedGroup) {
                if(groupOrderCounter[gr] == 0 and unGroupCounter[gr] == 0) {
                    sortingGroupItems(group, gr);
                }
            }
            
            if(beforeSize == res.size())
                return {};
            
            eraseUsedGroupAndItems(group, beforeSize);
        }
        
        return res;
        
    }
};