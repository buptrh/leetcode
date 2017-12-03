class MyQueue {
public:
    stack<int> staIn;
    stack<int> staOut;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!staOut.empty()) {
            staIn.push(staOut.top());
            staOut.pop();
        }
        staIn.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        staOut.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        while(!staIn.empty()) {
            staOut.push(staIn.top());
            staIn.pop();
        }
        return staOut.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return staIn.empty() && staOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */