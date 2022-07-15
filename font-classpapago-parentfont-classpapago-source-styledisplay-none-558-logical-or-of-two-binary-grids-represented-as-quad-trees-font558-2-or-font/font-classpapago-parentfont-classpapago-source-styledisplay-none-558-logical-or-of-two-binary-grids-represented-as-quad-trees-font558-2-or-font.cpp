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
public:
    Node* intersect(Node* A, Node* B) {
        if(A->isLeaf and A->val) return A;
        if(B->isLeaf and B->val) return B;
        if(A->isLeaf and !A->val) return B;
        if(B->isLeaf and !B->val) return A;
        auto tl = intersect(A->topLeft, B->topLeft), tr = intersect(A->topRight, B->topRight), bl = intersect(A->bottomLeft, B->bottomLeft), br = intersect(A->bottomRight, B->bottomRight);
        if(tl->val == tr->val and tl->val == bl->val and tl->val == br->val and tl->isLeaf and tr->isLeaf and bl->isLeaf and br->isLeaf) return new Node(tl->val, true);
        return new Node(tl->val or tr->val or bl->val or br->val, false, tl, tr, bl, br);
    }
};