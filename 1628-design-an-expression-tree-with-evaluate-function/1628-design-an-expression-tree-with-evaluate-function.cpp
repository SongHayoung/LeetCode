/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() {
        if(isdigit(exp[0])) {
            return stoi(exp);
        } else {
            int l = left->evaluate();
            int r = right->evaluate();
            if(exp == "+") return l + r;
            else if(exp == "-") return l - r;
            else if(exp == "*") return l * r;
            else return l / r;
        }
    }
    Node(string exp) : exp(exp), left(nullptr), right(nullptr) {};
    void setChild(Node* l, Node* r) {
        left = l;
        right = r;
    }
protected:
    // define your fields here
    string exp;
    Node *left, *right;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        vector<Node*> st;
        for(auto& p : postfix) {
            st.push_back(new Node(p));
            if(!isdigit(p[0])) {
                auto root = st.back(); st.pop_back();
                auto r = st.back(); st.pop_back();
                auto l = st.back(); st.pop_back();
                root->setChild(l,r);
                st.push_back(root);
            }
        }
        return st[0];
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */