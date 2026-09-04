
class AuctionSystem {
    unordered_map<int, unordered_map<int, int>> bids;
    unordered_map<int, multiset<pair<int,int>>> ords;
    bool has(int userId, int itemId) {
        if(!bids.count(userId)) return false;
        return bids[userId].count(itemId);
    }
    void del(int userId, int itemId) {
        ords[itemId].erase({bids[userId][itemId], userId});
        if(ords[itemId].size() == 0) ords.erase(itemId);
        bids[userId].erase(itemId);
        if(bids[userId].size() == 0) bids.erase(userId);
    }
    void add(int userId, int itemId, int amount) {
        bids[userId][itemId] = amount;
        ords[itemId].insert({amount, userId});
    }
public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if(has(userId,itemId)) {
            del(userId,itemId);
        }
        add(userId,itemId,bidAmount);
    }

    void updateBid(int userId, int itemId, int newAmount) {
        if(!has(userId,itemId)) return;
        del(userId,itemId);
        add(userId,itemId,newAmount);
    }

    void removeBid(int userId, int itemId) {
        del(userId,itemId);
    }

    int getHighestBidder(int itemId) {
        if(!ords.count(itemId)) return -1;
        return prev(end(ords[itemId]))->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */