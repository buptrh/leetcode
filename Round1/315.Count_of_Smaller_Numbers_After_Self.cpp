class Solution {
public:
	class BSTNode {
	public:
		int val;
		int lCount;
		int count;
		BSTNode * left;
		BSTNode * right;
		BSTNode(int _val) {
			val = _val;
			count = 1;
			lCount = 0;
			left = NULL;
			right = NULL;
		}
		~BSTNode() {
			left = NULL;
			right = NULL;
		}

	};

	void AddNode(BSTNode * root, BSTNode * add) {
		// cout<<"AddNode" << add->val<<endl;
		if(add->val == root->val ){
			root->count++;
		} else if(root->val > add->val) {
			root->lCount++;
			if(root->left == NULL) {
				root->left = add;
			} else  {
				AddNode(root->left, add);
			} 
		} else {
			if(root->right == NULL) {
				root->right = add;
			} else {
				AddNode(root->right, add);
			}
		}
	}

	int SearchTree(BSTNode * node, int val) {
		if(node == NULL) {
			return 0;
		}
		// cout<< node->val << "  " << val << endl;
		if(node->val < val) {
			return node->lCount + node->count + SearchTree(node->right, val);
		} else if(node->val == val) {
			return node->lCount;
		} else {
			return SearchTree(node->left, val);
		}
	}

	void DeleteTree(BSTNode * node) {
		if(node == NULL) {
			return;
		}
		DeleteTree(node->left);
		DeleteTree(node->right);
		delete node;
	}

    vector<int> countSmaller(vector<int>& nums) {
    	std::vector<int> vRet;
    	if(nums.size() == 0) {
    		return vRet;
    	} else if(nums.size() == 1) {
    		vRet.emplace_back(0);
    		return vRet;
    	}
    	BSTNode * root = NULL;
        for(int i = nums.size()-1; i >= 0; i--) {
        	// cout<<"~~" << i<< "  "<<nums[i]<<endl;
        	if(root == NULL) {
        		root = new BSTNode(nums[i]);
        		vRet.emplace_back(0);
        	} else {
        		int ret = SearchTree(root, nums[i]);
        		// cout<<"!!!Add" << ret<<". " << nums[i] << endl;
        		vRet.emplace_back( ret );
        		AddNode(root, new BSTNode(nums[i]));
        	}
        }

        DeleteTree(root);

        reverse(vRet.begin(), vRet.end());
        return vRet;
    }
};
// another solution see #327