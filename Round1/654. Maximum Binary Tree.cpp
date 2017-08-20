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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(std::vector<int> & nums, int start, int end) {
    	if(start == end) {
    		return new TreeNode(nums[start]);
    	} else if(start > end) {
    		return NULL;
    	}
    	int val = INT_MIN, index = 0;
        for(int i = start; i <= end; i++) {
        	if(nums[i] > val) {
        		index = i;
        		val = nums[i];
        	}
        }
        TreeNode* node = new TreeNode(val);
        node->left = helper(nums, start, index-1);
        node->right = helper(nums, index+1, end);
        return node;
    }
};