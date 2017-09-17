//  Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

// Example 1:

// Input:     
//     5
//    / \
//   10 10
//     /  \
//    2   3

// Output: True
// Explanation: 
//     5
//    / 
//   10
      
// Sum: 15

//    10
//   /  \
//  2    3

// Sum: 15

// Example 2:

// Input:     
//     1
//    / \
//   2  10
//     /  \
//    2   20

// Output: False
// Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.

// Note:

//     The range of tree node value is in the range of [-100000, 100000].
//     1 <= n <= 10000


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
    bool checkEqualTree(TreeNode* root) {
        int sum = helper1(root);
        if(sum%2 != 0) {
          return false;
        }
        bool ret = false;
        helper(root, sum, ret);
        return ret;
    }

    int helper1(TreeNode* root) {
      int ret = 0;
      if(root->left != NULL) {
        ret += helper1(root->left);
      }

      if(root->right != NULL) {
        ret += helper1(root->right);
      }
      ret += root->val;
      return ret;
    }

    int helper(TreeNode* root, int sum, bool & ret) {
      int v = 0; 
      
      if(ret) {
        return true;
      }
      int sumVal = 0;
      if(root->left != NULL) {
        v = helper(root->left, sum, ret);
        sumVal += v;
        if(ret || v == sum/2) {
          ret = true;
        }
      }
      if(ret) {
        return true;
      }

      if(root->right != NULL) {
        v = helper(root->right, sum, ret);
        sumVal += v;
        if(ret || v == sum/2) {
          ret = true;
        }
      }
      sumVal += root->val;
      return sumVal;
    }
};











