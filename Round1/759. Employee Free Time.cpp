/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        vector<int> indexes(avails.size(), 0);
        int minTime = INT_MIN, minStart = INT_MAX;
        bool flag = false;
        bool hasData = true;
        vector<Interval> res;
        while(hasData) {
        	flag = false;
        	hasData = false;
	        for(int i = 0; i < avails.size(); i++) {
	        	while(indexes[i] < avails[i].size() && avails[i][indexes[i]].end < minTime) {
	        		indexes[i]++;
	        	}
	        	if(indexes[i] < avails[i].size()) {
	        		hasData = true;
	        		if(avails[i][indexes[i]].start <= minTime) {
		        		minTime = max(minTime, avails[i][indexes[i]].end);
		        		cout << "change MinTime: " << avails[i][indexes[i]].end << endl;
		        		indexes[i]++;
		        		flag = true;
		        		minStart = INT_MAX;
		        	} else {
		        		cout<<" flag:  " << avails[i][indexes[i]].start << endl;
		        		minStart = min(minStart, avails[i][indexes[i]].start);
		        	}
	        	}

	        	cout<< i << "  " << indexes[i] << "  " << avails[i].size() <<endl;
	        }
	        cout<<"~~" <<minTime <<".  " << minStart << endl;
	        if(!flag) {
	        	if(minTime != INT_MIN && minStart > minTime && minStart != INT_MAX) {
	        		cout<<"output:  " << minTime << "  " << minStart<<endl;
	        		res.push_back(Interval(minTime, minStart));
	        	}
	        	minTime = minStart;
	        	minStart = INT_MAX;
	        }
        }
        return res;
    }
};