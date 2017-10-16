/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// see #449
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        queue<TreeNode*> traversal;
        traversal.emplace(root);
        while(traversal.size() > 0) {
        	TreeNode * node = traversal.front();
        	traversal.pop();
        	if(ret.size() > 0 ) {
        		ret += ",";
        	}
        	if(node == NULL) {
        		ret += "#";
        		continue;
        	}
        	ret += to_string(node->val) ;
        	traversal.emplace(node->left);
        	traversal.emplace(node->right);
        }
        // cout<<ret<<endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int nextPos = data.find(',', 0), pos = 0;
        bool newNode = true;
        TreeNode * root = NULL, *parent = root;
        queue<TreeNode*> traversal;
        while(nextPos >= 0) {
        	string number = data.substr(pos, nextPos - pos);
        	pos = nextPos + 1;
        	nextPos = data.find(',', pos);
        	if(root == NULL) {
        		newNode = true;
	        	if(number == "#" ) {
	        		root = NULL;
	        	} else {
	        		root = new TreeNode(stoi(number));
    				traversal.emplace(root);
	        	}
        	} else {
	        	if(newNode) {
		        	parent = traversal.front();
		        	traversal.pop();
		        	newNode = false;
		        	if(number == "#" ) {
		        		parent->left = NULL;
		        	} else {
		        		parent->left = new TreeNode(stoi(number));
	    				traversal.emplace(parent->left);
		        	}
	        	} else {
	        		newNode = true;

		        	if(number == "#" ) {
		        		parent->right = NULL;
		        	} else {
		        		parent->right = new TreeNode(stoi(number));
	    				traversal.emplace(parent->right);
		        	}
	        	}
        	}
        }


        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));