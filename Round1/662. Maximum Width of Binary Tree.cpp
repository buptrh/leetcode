// Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

// Example 1:

// Input: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

// Example 2:

// Input: 

//           1
//          /  
//         3    
//        / \       
//       5   3     

// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).

// Example 3:

// Input: 

//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).

// Example 4:

// Input: 

//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


// Note: Answer will in the range of 32-bit signed integer.


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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
          return 0;
        }
        if(root->left == NULL && root->right == NULL) {
          return 1;
        }
        queue<TreeNode*> que;
        que.push(root);
        int ret = 0;
        while(que.size() != 0) {
          int size = que.size();
          vector<TreeNode*> vec;
          int level = 0;
          for(int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if(node == NULL) {
              vec.push_back(NULL);
              vec.push_back(NULL);
            } else {
              vec.push_back(node->left);
              vec.push_back(node->right);
            }
          }
          int from = vec.size()-1, to = 0;
          for(int i = vec.size()-1; i >= 0; i--) {
            if(vec[i] != NULL) {
              to = i;
              break;
            }
          }
          for(int i = 0; i < vec.size(); i++) {
            if(vec[i] != NULL) {
              from = i;
              break;
            }
          }
          level = to - from + 1;   
          for(int i = from; i <= to; i ++) {
            // cout<<vec.size() << "  " << from << "  " << to << endl;
            que.push(vec[i]);
          }
          ret = max(ret, level);
        }
        return ret;
    }

};







