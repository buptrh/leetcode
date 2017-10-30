#include <iostream>
#include <vector>
using namespace std;

int CoverIntervals(vector<pair<int, int>> & intervals) {
	if(intervals.size() == 0) {
		return 0;
	}
	auto comp = [](pair<int, int> a, pair<int, int> b) {
	    return a.first < b.first;
	};
	sort(intervals.begin(), intervals.end(), comp);

	int rightEdge = intervals[0].first;
	int maxRight = intervals[0].second;
	int count = 0;
    bool changed = false;
	for(int i = 0; i < intervals.size(); i++) {
		if(intervals[i].first > rightEdge) {
			count++;
			rightEdge = maxRight;
			maxRight = intervals[i].second;
			changed = false;
		} else {
			if(intervals[i].second > maxRight) {
				maxRight = intervals[i].second;
				changed = true;
			}
		}
	}
	if(changed) {
		count++;
	}
	return count;
}

int main() {
	vector<pair<int, int>> intervals;
	// intervals.push_back(pair<int, int>(0, 1));
	intervals.push_back(pair<int, int>(2, 10));
	intervals.push_back(pair<int, int>(3, 9));
	intervals.push_back(pair<int, int>(5, 8));
	intervals.push_back(pair<int, int>(7, 7));
	intervals.push_back(pair<int, int>(9, 5));

	cout<<CoverIntervals(intervals)<<endl;;
}