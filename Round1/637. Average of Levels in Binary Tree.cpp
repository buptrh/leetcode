/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
    	if(root == NULL) {
    		return ret;
    	}
        queue<TreeNode*> arr;
        arr.emplace(root);
        int current = 1, next = 0,  currentCount = 1;
        long long sum = 0;
        while(arr.size() > 0) {
        	TreeNode * node = arr.front();
        	arr.pop();
        	current--;
    		if(node->left != NULL) {
        		arr.emplace(node->left);
        		next++;
    		}

    		if(node->right != NULL) {
        		arr.emplace(node->right);
        		next++;
    		}
        	sum += node->val;
        	if(current <= 0) {
        		ret.emplace_back((double)sum/(double)currentCount);
        		current = next;
        		currentCount = next;
        		next = 0;
        		sum = 0;
        	}
        	// cout << node->val << "  " << current<< "  " << next<<endl;
        }
        return ret;
    }
};