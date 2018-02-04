// #include "mutex"
class LRUCache {
public:
	class Node {
	public:
		Node* pre;
		Node* next;
		int key;
		int val;
	};
	int capacity;
	int length;
	Node* root;
	unordered_map<int, Node*> nodesMap;
    // std::mutex mu;

    LRUCache(int c) {
        capacity = c;
        length = 0;
        root = new Node();
        root->next = root;
        root->pre = root;
    }

    void removeNode(Node* node) {
    	if(length == 0) {
    		return;
    	}
    	node->pre->next = node->next;
    	node->next->pre = node->pre;
    	nodesMap[node->key] = NULL;
    	length--;
    }
    
    void addNodeToTop(Node* node) {
    	node->next = root->next;
    	node->next->pre = node;
    	root->next = node;
    	node->pre = root;
    	nodesMap[node->key] = node;
    	length++;
    }
    
    int get(int key) {
    	// std::lock_guard <std::mutex> locker(mu);
    	Node* node = nodesMap[key];
        if(node != NULL) {
        	removeNode(node);
        	addNodeToTop(node);
        	return node->val;
        } else {
        	return -1;
        }
    }
    
    void put(int key, int value) {
    	// std::lock_guard <std::mutex> locker(mu);
    	Node* node = nodesMap[key];
        if(node == NULL) {
        	node = new Node();
        } else {
        	removeNode(node);
        }
        node->val = value;
        node->key = key;
    	addNodeToTop(node);
    	if(length > capacity) {
    		Node* del = root->pre;
    		removeNode(del);
    		delete del;
    	}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */