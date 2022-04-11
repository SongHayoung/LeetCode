/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "";
        string res = to_string(root->val) + ' ';
        if(root->children.size()) {
            res += '[';
            for(auto ch : root->children) res += serialize(ch) + ' ';
            res += ']';
        }
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.length() == 0) return NULL;
        int i = 0;
        return deserialize(data,i)[0];
    }
    
    vector<Node*> deserialize(string& data, int &i) {
        vector<Node*> nodes;
        while(i < data.length() and data[i] != ']') {
            if(data[i] == '[') nodes.back()->children = deserialize(data,++i);
            else if(data[i] == ' ') i++;
            else {
                nodes.push_back(new Node(parse(data, i)));
            }
        }
        i++;
        return nodes;
    }
    
    int parse(string& s, int& i) {
        int res = 0;
        while(i < s.length() and isdigit(s[i])) {
            res = res * 10 + (s[i++] & 0b1111);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));