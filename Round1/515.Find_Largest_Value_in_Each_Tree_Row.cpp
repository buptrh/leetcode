/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//bfs
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> nodes;
        std::vector<int> vRet;
        if(root == NULL) {
        	return vRet;
        }
        nodes.emplace(root);
        int level = 0, countOfLevel = 1, countOfNext = 0;;
        while(nodes.size() > 0) {
        	TreeNode * node = nodes.front();
        	nodes.pop();
        	countOfLevel --;

        	if(vRet.size() <= level){
        		vRet.emplace_back(INT_MIN);
        	}
        	vRet[level] = max(vRet[level],  node->val);
        	if(node->left != NULL) {
        		countOfNext++;
        		nodes.emplace(node->left);
        	}

        	if(node->right != NULL) {
        		countOfNext++;
        		nodes.emplace(node->right);
        	}

        	if(countOfLevel <= 0) {
        		countOfLevel = countOfNext;
        		countOfNext = 0;
        		level++;
        	}
        }

        return vRet;
    }
};

//dfs  use Recursion
