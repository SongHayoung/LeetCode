class FileSharing {
    vector<set<int>> joins;
    unordered_map<int, unordered_set<int>> own;
    int id = 1;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    FileSharing(int m) {
        joins = vector<set<int>>(m + 1);
    }
    
    int join(vector<int> ownedChunks) {
        int userId;
        if(!q.empty()) {
            userId = q.top(); q.pop();
        } else userId = id++;
        own[userId] = unordered_set<int>(begin(ownedChunks), end(ownedChunks));
        for(auto& o : ownedChunks)
            joins[o].insert(userId);
        return userId;
    }
    
    void leave(int userID) {
        for(auto& o : own[userID])
            joins[o].erase(userID);
        own.erase(userID);
        q.push(userID);
    }
    
    vector<int> request(int userID, int chunkID) {
        vector<int> res = vector<int>(begin(joins[chunkID]), end(joins[chunkID]));
        if(!own[userID].count(chunkID) and !res.empty()) {
            joins[chunkID].insert(userID);
            own[userID].insert(chunkID);
        }
        return res;
    }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */