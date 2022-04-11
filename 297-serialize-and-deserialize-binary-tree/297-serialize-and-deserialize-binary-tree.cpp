/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    const string NON = "N";
    const string SLASH = "/";
    int _stoi(string& s) {
        int res = 0;
        bool minus = s[0] == '-';
        for(int i = minus ? 1 : 0; i < s.length(); i++) {
            res = res * 10 + (s[i] & 0b1111);
        }
        return minus ? -res : res;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* node) {
        return !node ? NON : to_string(node->val) + SLASH + serialize(node->left) + SLASH + serialize(node->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return _deserialize(data, pos);
    }

    TreeNode* _deserialize(string& data, int& pos) {
        auto nextPos = data.find(SLASH, pos);
        if(nextPos == string::npos) return nullptr;
        string d = data.substr(pos, nextPos - pos);
        pos = nextPos + 1;
        return d == NON ? nullptr : new TreeNode(_stoi(d), _deserialize(data, pos), _deserialize(data, pos));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
