class Solution {
public:

struct cmp{
    bool operator() ( int a, int b ){
        return a>b; 
    }
};
    int nthUglyNumber(int n) {
    	priority_queue<int, vector<int>, cmp> queue;
    	queue.push(1);
    	int count = 0;
    	int val = 1, old = 0;
    	while(count < n) {
    		val = queue.top();
    		queue.pop();
    		if(old != val) {
	    		count++;
	    		if(val < INT_MAX/2) {
	    			queue.push(val * 2);
	    		}
	    		if(val < INT_MAX/3) {
	    			queue.push(val * 3);
	    		}
	    		if(val < INT_MAX/5) {
	    			queue.push(val * 5);
	    		}
    		}
    		old = val;
    	}
    	return val;
    }
};


//priority_queue is slow.