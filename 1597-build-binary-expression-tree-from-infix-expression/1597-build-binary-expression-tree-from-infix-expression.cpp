/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    Node* build(string& s, int l, int r) {
        Node* op = new Node(s[l + (r-l)/2]);
        op->left = new Node(s[l]);
        op->right = new Node(s[r]);
        return op;
    }
    int find(string& s, int l, int r, char op1, char op2) {
        int st = 0;
        for(int i = r; i >= l; i--) {
            if(s[i] == '(') st++;
            else if(s[i] == ')') st--;
            else if(st == 0 and (s[i] == op1 or s[i] == op2)) return i;
        }
        return -1;
    }
    int findFirstOutBound(string& s, int l, int r) {
        int st = 1;
        for(int i = l + 1; i <= r; i++) {
            if(s[i] == '(') st++;
            else if(s[i] == ')') st--;
            if(st == 0) return i;
        }
        return r;
    }
    Node* helper(string& s, int l, int r) {
        if(r - l + 1 == 3) return build(s,l,r);
        if(l == r) return new Node(s[l]);
        int p = find(s, l, r,'+','-');
        if(p != -1) {
            Node* op = new Node(s[p]);
            op->left = helper(s,l,p-1);
            op->right = helper(s,p+1,r);
            return op;
        } else {
            if(s[l] == '(') {
                int boundp = findFirstOutBound(s,l,r);
                if(boundp == r)
                    return helper(s,l+1,r-1);
                Node* op = new Node(s[boundp + 1]);
                op->left = helper(s,l+1,boundp-1);
                op->right = helper(s,boundp+2,r);
                return op;
            } else {
                int opp = find(s,l,r,'*','/');
                Node* op = new Node(s[opp]);
                op->left = helper(s,l,opp-1);
                op->right = helper(s,opp+1,r);
                return op;
            }
        }
        
    }
public:
    Node* expTree(string s) {
        return helper(s,0,s.length() - 1);
    }
};