class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int visit = 1;
        queue<int> keys;
        vector<bool> v(rooms.size(), false);
        v[0] = true;
        for(auto key : rooms[0])
            if(!v[key]){
                keys.push(key);
                v[key] = true;
                visit++;
            }
        
        while(!keys.empty()) {
            auto key = keys.front();
            keys.pop();
            for(auto key : rooms[key])
                if(!v[key]){
                    keys.push(key);
                    v[key] = true;
                    visit++;
                }
        }
        return visit == rooms.size();
    }
};
