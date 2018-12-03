class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {

    	auto comp = [quality, wage](int a, int b) {
		    return ((double)wage[a]/(double)quality[a]) < ((double)wage[b]/(double)quality[b]);
		};
		priority_queue<int, vector<int>, decltype(comp)> queue(comp);
		// priority_queue<double> ratio(comp);

		for(int i = 0; i < quality.size(); i++) {
			queue.push(i);
			if(queue.size() > K) {
				queue.pop();
			}
		}
        
        int cheapest = queue.top();
        double rate = (double)wage[cheapest] / (double)quality[cheapest];
        while(queue.size > 0) {
        	// cout<<one.first<< "  " << one.second<<endl;
        	ret += rate * (double)quality[queue.top()];
        	queue.pop();
        }
        return ret;

    }
};