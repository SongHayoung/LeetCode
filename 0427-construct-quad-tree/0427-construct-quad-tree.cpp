/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool allEqual(vector<vector<int>>& g, pair<int, int> topLeft, pair<int,int> bottomRight) {
        auto [sy, sx] = topLeft;
        auto [ey, ex] = bottomRight;
        for(int i = sy; i <= ey; i++) {
            for(int j = sx; j <= ex; j++) {
                if(g[sy][sx] != g[i][j]) return false;
            }
        }
        return true;
    }
    Node* conquer(Node* tl, Node* tr, Node* bl, Node* br) {
        return new Node(true, false, tl, tr, bl, br);
    }
    Node* divde(vector<vector<int>>& grid, pair<int, int> topLeft, pair<int,int> bottomRight) {
        if(allEqual(grid,topLeft,bottomRight)) {
            return new Node(grid[topLeft.first][topLeft.second], true);
        }
        int midY = (bottomRight.first + topLeft.first) / 2;
        int midX = (bottomRight.second + topLeft.second) / 2;
        Node *tl = divde(grid, topLeft, {midY,midX});
        Node *tr = divde(grid, {topLeft.first, midX + 1}, {midY, bottomRight.second});
        Node* bl = divde(grid, {midY + 1, topLeft.second}, {bottomRight.first, midX});
        Node* br = divde(grid, {midY + 1, midX + 1}, bottomRight);
        return conquer(tl, tr, bl, br);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return divde(grid, {0,0}, {grid.size() - 1, grid.size() - 1});
    }
};