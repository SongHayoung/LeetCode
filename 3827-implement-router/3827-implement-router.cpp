
class Router {
    deque<vector<int>> packets;
    unordered_map<int,deque<int>> destPackets;
    set<vector<int>> setPackets;
    int size;
public:
    Router(int memoryLimit) : size(memoryLimit) {
    }

    bool addPacket(int source, int destination, int timestamp) {
        if(setPackets.count({source, destination, timestamp})) return false;
        if(packets.size() == size) forwardPacket();
        vector<int> packet{source,destination,timestamp};
        destPackets[destination].push_back(timestamp);
        setPackets.insert(packet);
        packets.push_back(packet);
        return true;
    }

    vector<int> forwardPacket() {
        if(packets.size() == 0) return {};
        vector<int> res = packets[0]; packets.pop_front();
        destPackets[res[1]].pop_front();
        setPackets.erase(res);
        return res;
    }

    int getCount(int destination, int startTime, int endTime) {
        return std::upper_bound(destPackets[destination].begin(), destPackets[destination].end(),endTime) -
                std::lower_bound(destPackets[destination].begin(), destPackets[destination].end(),startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */