// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

Node* LCA(Node * root , int l , int h);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}// } Driver Code Ends


bool inRange(int mi, int ma, int target) {
    return mi < target and target < ma;
}

pair<bool, Node*> helper(Node* node, int v1, int v2, int mi, int ma) {
    if(!node) return{false, nullptr};
    if(!(inRange(mi, ma, v1) or inRange(mi, ma, v2))) return {false, nullptr};
    
    
    if(node->data == v1) {
        auto rp = helper(node->right, v1, v2, v1, ma);
        if(rp.first) return {true, node};
        return {true, nullptr};
    } else if(node->data == v2) {
        auto lp = helper(node->left, v1, v2, mi, v2);
        if(lp.first) return {true, node};
        return {true, nullptr};
    }
    if(inRange(mi, ma, v1) or inRange(mi, ma, v2)) {
        auto lp = helper(node->left, v1, v2, mi, node->data);
        if(lp.second) return lp;
        auto rp = helper(node->right, v1, v2, node->data, ma);
        if(rp.second) return rp;
        if(lp.first && rp.first) return {true, node};
        if(lp.first) return lp;
        if(rp.first) return rp;
        return {false, nullptr};   
    } else if(inRange(mi, ma, v1)) {
        return helper(node->left, v1, v2, mi, node->data);
    } else {
        return helper(node->right, v1, v2, node->data, ma);
    }
}
Node* LCA(Node *root, int n1, int n2) {
   return helper(root, min(n1,n2), max(n1,n2), INT_MIN, INT_MAX).second;
}


