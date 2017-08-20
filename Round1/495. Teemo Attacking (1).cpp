class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    	int current = -duration, ret = 0;
        for(int i = 0; i < timeSeries.size(); i++) {
        	if(timeSeries[i] < current + duration) {
        		ret -= current + duration - timeSeries[i];
        		// cout <<"!!" <<endl;
        	}
        	current = timeSeries[i];
        	ret += duration;
        }
        return ret;
    }
};