class MinStack {

    class Node {
    public:
        Node(int v) { value = v;  next = NULL; min = v;}
        int value;
        Node* next;
        int min;
    };

public:
    /** initialize your data structure here. */

    Node * topNode;
    MinStack() {
        topNode = NULL;
    }
    
    void push(int x) {
        Node * node = new Node(x);
        if(topNode == NULL) {
            topNode = node;
        } else {
            node->next = topNode;
            node->min = min(topNode->min, node->value);
            topNode = node;
        }
    }
    
    void pop() {
        Node * node = topNode->next;
        delete topNode;
        topNode = node;
    }
    
    int top() {
        return topNode->value;
    }
    
    int getMin() {
        return topNode->min;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */