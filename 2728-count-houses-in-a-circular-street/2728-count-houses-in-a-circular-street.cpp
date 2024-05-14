/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        for(int i = 0; i < k; i++) {
            if(street->isDoorOpen()) street->closeDoor();
            street->moveRight();
        }
        street->openDoor();
        int res = 1;
        while(1) {
            street->moveRight();
            if(street->isDoorOpen()) break;
            res++;
        }
        return res;
    }
};