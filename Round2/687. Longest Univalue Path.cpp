/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct MyTreeNode {
	vector<int> children;
};
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
    	if(root == NULL) {
    		return 0;
    	}
    	vector<int> nodes;
    	vector<int> ways;
        transform(root, nodes, ways);
        vector<vector<int>> input;
        input.push_back(nodes);
        input.push_back(ways);

    	vector<vector<int>> newTree(input[0].size(), vector<int>());
    	formatNewTree(newTree, input);
    	int maxValue = 0;
    	answer(newTree, input, 0, maxValue);
    	return maxValue-1;
    }

    void transform(TreeNode* root, vector<int> & nodes, vector<int> & ways) {
    	queue<TreeNode*> que;
    	if(root == NULL) {
    		return;
    	}
    	que.push(root);
    	int previndex = 0, nextindex = 1;
    	while(que.size() != 0) {
    		int size = que.size();
    		for(int i = 0; i < size; i++) {
    			TreeNode* node = que.front();
    			que.pop();
    			nodes.push_back(node->val);
    			if(node->left != NULL) {
    				ways.push_back(previndex);
    				ways.push_back(nextindex);
    				que.push(node->left);
    				nextindex++;
    			}
    			if(node->right != NULL) {
    				ways.push_back(previndex);
    				ways.push_back(nextindex);
    				que.push(node->right);
    				nextindex++;
    			}
				previndex++;
    		}
    	}

    	// cout<<"nodes ";
    	// for(int i = 0; i < nodes.size(); i++) {
    	// 	cout<<nodes[i]<< "  " ;
    	// }
    	// cout<<endl;

    	// cout<<"ways ";
    	// for(int i = 0; i < ways.size(); i++) {
    	// 	cout<<ways[i]<< "  " ;
    	// }
    	// cout<<endl;
    }

    void formatNewTree(vector<vector<int>> & newTree, vector<vector<int>> & input) {
    	for(int i = 0; i < input[1].size(); i += 2) {
    		newTree[input[1][i]].push_back(input[1][i+1]);
    	}

    	// for(int i = 0; i < newTree.size(); i++) {
    	// 	cout <<" " << i << "  " << input[0][i] <<" : ";
    	// 	for(int j = 0; j < newTree[i].size(); j++) {
    	// 		cout << newTree[i][j] << "  " ;
    	// 	}
    	// 	cout<<endl;
    	// }
    }

    int answer(vector<vector<int>> & newTree, vector<vector<int>> & input, int index, int & maxValue) {
    	int max1 = 0, max2 = 0;
    	for(int i = 0; i < newTree[index].size(); i++) {
    		int child = newTree[index][i];
    		int v = answer(newTree, input, child, maxValue);
    		if(input[0][index] == input[0][child]) {
    			if(v > max1) {
    				int temp = max1;
    				max1 = v;
    				v = temp;
    			}
    			if(v > max2) {
    				max2 = v;
    			}
    		}
    	}
    	int res = max1 + 1;

    	maxValue = max(maxValue, max1 + max2 + 1);
    	return res;
    }
};