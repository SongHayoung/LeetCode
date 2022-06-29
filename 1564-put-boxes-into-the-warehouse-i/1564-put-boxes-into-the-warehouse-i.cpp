class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        for(int i = 1; i < warehouse.size(); i++) {
            if(warehouse[i] > warehouse[i - 1])
                warehouse[i] = warehouse[i - 1];
        }
        sort(boxes.begin(), boxes.end());
        int res = 0;
        for(int i = warehouse.size() - 1; i >= 0 and res < boxes.size(); i--) {
            if(warehouse[i] >= boxes[res])
                res++;
        }
        return res;
    }
};