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
    int minMeetingRooms(vector<Interval>& intervals) {
    	auto comp = [](Interval & a, Interval & b) {
    		return a.start < b.start;
    	};
    	sort(intervals.begin(), intervals.end(), comp);

    	auto comp2 = [](Interval & a, Interval & b) {
    		return a.end > b.end;
    	};
        priority_queue<Interval, vector<Interval>, decltype(comp2)> que(comp2);

        int res = 0;
        for(Interval val : intervals) {
        	while(que.size() > 0 && que.top().end <= val.start) {
        		que.pop();
        	}
        	que.push(val);
        	res = max(res, (int)que.size());
        }
        return res;
    }
};