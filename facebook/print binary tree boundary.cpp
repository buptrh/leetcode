class Node {
	Node* left;
	Node* right;
	int val;
};

void printTreeBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	cout<<root->val << endl;
	dfs(root->right, true, false);
	dfs(root->left, true, true);
}

void dfs(Node* root, bool print, bool left) {
	if(root == NULL) {
		return;
	}
	if((print && !left) || ( root->right == NULL && root->left == NULL)) {
		cout<<root->val << endl;
	}
	
	dfs(root->right, print && !left, false;);
	dfs(root->left, print && left, true);

	if(print && left) {
		cout<<root->val << endl;
	}
}