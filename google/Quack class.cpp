
// 给定一个Quack class。基本上就是一个a stack or queue，已经按升序排好， 
// .pop() will randomly pop from head or tail of this data structure. 
// 要求返利用这个.pop()，返回降序排列的 array。
class Node{
	int val;
}
class Quack {
	// pop();
	vector<Node*> getDecendingArray() {
		vector<Node*> maxArr;
		vector<Node*> minArr;
		Node* cur = pop();
		Node* temp = NULL;
		while(cur != NULL) {
			if(temp != NULL) {
				if(temp->val > cur->val) {
					maxArr.push_back(temp);
				} else {
					minArr.push_back(temp);
				}
			}
			temp = cur;
		}

		reverse(minArr.begin(), minarr.end());
		maxArr.push_back(temp);
		for(Node* node : minarr) {
			maxArr.push_back(node);
		}
		return maxArr;
	}
}