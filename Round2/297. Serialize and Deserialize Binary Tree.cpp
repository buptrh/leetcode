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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serializePreorder(root) + "!" + serializeInorder(root);
    }

    string serializeInorder(TreeNode* root) {
		if(root == NULL) {
    		return "";
    	}
    	string left = serializePreorder(root->left);
    	string right = serializePreorder(root->right);
    	string ret = to_string(root->val);
    	if(left.size() != 0) {
    		ret = left + ":" + ret;
    	}
    	if(right.size() != 0) {
    		ret = ret + ":" + right;
    	}
    }

    string serializePreorder(TreeNode* root) {
    	if(root == NULL) {
    		return "";
    	}
    	string left = serializePreorder(root->left);
    	string right = serializePreorder(root->right);
    	string ret = to_string(root->val);
    	if(left.size() != 0) {
    		ret = ret + ":" + left;
    	}
    	if(right.size() != 0) {
    		ret = ret + ":" + right;
    	}
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string pre = "";
        string in = "";
        bool flag = true;
        for(char c : data) {
        	if(c == '!') {
        		flag = false;
        		continue;
        	}
        	if(flag) {
        		pre += c;
        	} else {
        		in += c;
        	}
        }

    }
    TreeNode * deserializeTree(string pre, string in) {
    	
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));