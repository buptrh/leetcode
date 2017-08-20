class MyStack {
public:
    queue<int> queIn;
    queue<int> queOut;
    int front;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        front = x;
        queIn.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(queIn.size() > 1) {
            front = queIn.front();
            queOut.push(front);
            queIn.pop();
        }
        int val = queIn.front();
        queIn.pop();
        queIn = queOut;
        std::queue<int>().swap(queOut);
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return front;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queIn.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */