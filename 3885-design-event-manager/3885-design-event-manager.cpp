class EventManager {
    set<pair<int,int>> s;
    unordered_map<int,int> e;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto& event : events) {
            s.insert({event[1], -event[0]});
            e[event[0]] = event[1];
        }
    }

    void updatePriority(int eventId, int newPriority) {
        if(!e.count(eventId)) return;
        s.erase({e[eventId], -eventId});
        s.insert({newPriority, -eventId});
        e[eventId] = newPriority;
    }

    int pollHighest() {
        if(s.empty()) return -1;
        int id = s.rbegin()->second;
        s.erase(prev(end(s)));
        e.erase(-id);
        return -id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
