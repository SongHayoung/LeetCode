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
    void sHelper(TreeNode* node, string& res) {
        if(!node) res += "#,";
        else {
            res += to_string(node->val) + ',';
            sHelper(node->left, res);
            sHelper(node->right, res);
        }
    }
    int parseNum(string& s, int& p) {
        int res = 0;
        while(p < s.length() and isdigit(s[p])) {
            res = res * 10 + (s[p++] & 0b1111);
        }
        p++;
        return res;
    }
    TreeNode* dHelper(string& d, int& i) {
        if(i >= d.length() or d[i] == '#') {
            i += 2; return NULL;
        }
        
        TreeNode* node = new TreeNode(parseNum(d,i));
        node->left = dHelper(d,i);
        node->right = dHelper(d,i);
        
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        sHelper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p = 0;
        return dHelper(data, p);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;