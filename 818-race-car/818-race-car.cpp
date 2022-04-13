class Solution {
    int makeKey(int pos, int speed) {
        return speed * 10000 + (speed < 0 ? -pos : pos);
    }
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        unordered_set<int> visit;
        q.push({0,1});
        visit.insert(makeKey(0,1));
        for(int level = 1; !q.empty(); level++) {
            int sz = q.size();
            while(sz--) {
                auto [position, speed] = q.front(); q.pop();
                int reverseKey = makeKey(position, speed > 0 ? -1 : 1);
                if(!visit.count(reverseKey)) {
                    visit.insert(reverseKey);
                    q.push({position, speed > 0 ? -1 : 1});
                }
                int nextPosition = position + speed, nextSpeed = speed*2;
                int nextKey = makeKey(nextPosition, nextSpeed);
                if(!visit.count(nextKey) and 0 < nextPosition and nextPosition < target * 2) {
                    if(nextPosition == target) return level;
                    visit.insert(nextKey);
                    q.push({nextPosition, nextSpeed});
                }
            }
        }
        return -1;
    }
};