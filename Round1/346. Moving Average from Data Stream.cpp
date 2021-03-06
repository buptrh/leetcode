class MovingAverage {
public:
    /** Initialize your data structure here. */
    int sum;
    int s;
    queue<int> que;
    MovingAverage(int size) : s(size){
        sum = 0;
    }
    
    double next(int val) {
        que.push(val);
        sum += val;
        if(que.size() > s) {
        	sum -= que.front();
        	que.pop();
        }
        return (double)sum / (double) que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */