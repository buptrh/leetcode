/*
 * Complete the function below.
 */
vector <int> cutSticks(vector <int> lengths) {
	vector<int> res;
	queue<int> que;
	vector<int> nums;
	for(int i = 1; i <= lengths[0]; i++) {
		nums.push_back(lengths[i]);
	}
	sort(nums.begin(), nums.end());

	for(int val : nums) {
		que.push(val);
	}
	while(!que.empty()) {
		int size = que.size();
		int minVal = que.front();
		res.push_back(size);
		for(int i = 0; i < size; i++) {
			int val = que.front();
			que.pop();
			if(val - minVal > 0) {
				que.push(val - minVal);
			}
		}
	}
	return res;
}


//(A, B) (A, C) (B, G)
vector<pair<char, char>> transformToEdges(string nodes) {
	vector<pair<char, char>> res;
	for(int i = 0; i < nodes.size(); i += 6) {
		pair<char, char> edge;
		edge.first = nodes[i+1];
		edge.second = nodes[i+3];
		res.push_back(edge);
	}
	return res;
}
class Node {
public:
	Node(char c) {
		val = c;

	}
	vector<Node*> children;
	char val;
};

Node* transformToTree(const vector<pair<char, char>>& edges, string & error) {
	map<char, Node*> nodesMap;
	map<Node*, int> indegreeMap;
	for(auto & edge : edges) {
		if(nodesMap[edge.first] == NULL) {
			nodesMap[edge.first] = new Node(edge.first);
		}
		if(nodesMap[edge.second] == NULL) {
			nodesMap[edge.second] = new Node(edge.second);
		}
		Node* parent = nodesMap[edge.first];
		Node* child = nodesMap[edge.second];
		for(Node* node : parent->children) {
			if(node == child) {
				error = "E2";
				return NULL;
			}
		}
		parent->children.push_back(child);
		if(parent->children.size() > 2) {
			error = "E1";
			return NULL;
		}
        if(indegreeMap.find(parent) == indegreeMap.end()) {
            indegreeMap[parent] = 0;
        }
		indegreeMap[child]++;
	}
	Node* root = NULL;
	for(auto indegree : indegreeMap) {
		if(indegree.second != 0) {
			continue;
		}
		if(root == NULL) {
			root = indegree.first;
		} else {
			error = "E4";
			return NULL;
		}
	}
	return root;
}

string dfsTree(Node* root, string & error, unordered_set<Node*>& visited) {
	string res;
	if(root == NULL) {
		return res;
	}
	if(visited.find(root) != visited.end()) {
		error = "E3";
		return res;
	}
	visited.insert(root);
	if(root->children.size() == 0) {
		res += "(";
        res.push_back(root->val);
        res += ")";
	} else {
		res += "(";
        res.push_back(root->val);
		for(Node* node : root->children) {
			res += dfsTree(node, error, visited);
            if(error.size() > 0) {
                return "";
            }
		}
		res += ")";
	}
	return res;
}
/*
 * Complete the function below.
 */
string SExpression(string nodes) {
	vector<pair<char, char>> edges = transformToEdges(nodes);
	string error;
	Node* root = transformToTree(edges, error);
	unordered_set<Node*> visited;
	if(root == NULL) {
		if(error.size() == 0) {
			error = "E5";
		}
		return error;
	}
    // cout<<"start DFS"<<endl;
	string res = dfsTree(root, error, visited);
	if(error.size() != 0) {
		return error;
	} else {
		return res;
	}
}























