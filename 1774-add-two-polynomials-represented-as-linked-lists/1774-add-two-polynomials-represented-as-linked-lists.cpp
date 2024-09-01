/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy = new PolyNode(-1,-1);
        PolyNode* tail = dummy;
        while(poly1 and poly2) {
            if(poly1->power == poly2->power) {
                poly1->coefficient += poly2->coefficient;
                if(poly1->coefficient != 0) {
                    tail->next = poly1;
                    tail = tail->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if(poly1->power > poly2->power) {
                tail->next = poly1;
                poly1 = poly1->next;
                tail = tail->next;
            } else {
                tail->next = poly2;
                poly2 = poly2->next;
                tail = tail->next;
            }
            tail->next = nullptr;
        }
        if(poly1) tail->next = poly1;
        else if(poly2) tail->next = poly2;
        
        return dummy->next;
    }
};