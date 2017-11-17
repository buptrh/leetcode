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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }

    TreeNode* dfs(vector<int>& nums, int from, int to) {
    	if(from > to) {
    		return NULL;
    	}
    	int mid = from + (to - from) / 2;
    	TreeNode * node = new TreeNode(nums[mid]);
    	TreeNode * l = dfs(nums, from, mid-1);
    	TreeNode * r = dfs(nums, mid+1, to);
    	node->left = l;
    	node->right = r;
    	return node;
    }
};