

void printParens(int n) {
	helper(ret, path, n, n);
}

void helper(vector<string> & ret, string & path, int n, int m) {
	if(n == 0 && m == 0) {
		ret.push_back(path);
		cout<<path<<endl;
		return;
	}
	for(int i = 0; i < n; i++) {
		path.push_back('(');
		helper(ret, path, n-1, m);
		path.pop_back();
	}

	for(int i = 0; i < m; i++) {
		path.push_back(')');
		helper(ret, path, n, m-1);
		path.pop_back();
	}
}