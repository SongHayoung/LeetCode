class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> type;
        for(auto& candy : candyType) {
            type.insert(candy);
            if(type.size() >= candyType.size() / 2)
                return type.size();
        }
        return type.size();
    }
};
