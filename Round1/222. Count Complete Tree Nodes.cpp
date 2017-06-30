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
    int countNodes(TreeNode* root) {
        int count = 0, current = 1, level = 0, ret = 0;
        TreeNode * node = root;
        while(node != NULL) {
        	node = node->right;
        	count += current;
        	current = current << 1;
        	level++;
        }
        // cout<< count << "  " << current<< "  " << level << endl;

        int front = 0, end = current-1;
        while(front <= end) {
        	// cout << front << "  " << end <<endl;
        	int mid = front + (end - front) / 2;
        	int currentLevel = level;
			TreeNode * node = root;
			int multi = mid;
        	while(currentLevel > 0) {
        		int index = multi / ( 1 << (currentLevel-1));
        		multi = multi % (1 << (currentLevel-1));
        		// cout<<" index:" << index << "  multi:" << multi  << "  " << (1 << ( currentLevel-1))<< endl;
        		currentLevel--;
        		if(index == 0) {
        			node = node->left;
        		} else {
        			node = node->right;
        		}
        	}
    		// cout<< "!!mid"<<mid <<". ";
    		if(node != NULL) {
    			// cout<< node->val<<endl;
    			front = mid + 1;
    			ret = count + mid + 1;
    		} else {
    			// cout<< "null"<<endl;
    			end = mid - 1;
    		}
        	// cout << "~~" << front << "  "<< mid << "  " << end <<endl;
        }
        if(ret == 0) {
        	ret = count;
        }


        return ret;
    }
};