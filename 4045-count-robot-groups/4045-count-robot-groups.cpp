class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int res = 1;
        while(position.size() > 1) {
            if(position[position.size() - 1] - position[position.size() - 2] <= distance) {
                swap(speed[speed.size() - 1], speed[speed.size() - 2]);
                position.pop_back();
                speed.pop_back();
            } else if(speed[speed.size() - 1] < speed[speed.size() - 2]) {
                swap(speed[speed.size() - 1], speed[speed.size() - 2]);
                position.pop_back();
                speed.pop_back();
            } else {
                position.pop_back();
                speed.pop_back();
                res++;
            }
        }
        return res;
    }
};