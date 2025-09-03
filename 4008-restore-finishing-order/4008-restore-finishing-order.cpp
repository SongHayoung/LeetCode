class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> us(begin(friends), end(friends));
        for(int i = 0; auto& o : order) if(us.count(o)) friends[i++] = o;
        return friends;
    }
};