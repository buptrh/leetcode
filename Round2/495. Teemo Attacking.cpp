class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    	int ret = 0, startTime = -1;
        for(int i = 0; i < timeSeries.size(); i++) {
        	if(startTime != -1) {
        		ret += min(duration, (timeSeries[i] - startTime));
        	}
        	startTime = timeSeries[i];
        }
        if(timeSeries.size() != 0) {
        	ret += duration;
        }
        return ret;
    }
};