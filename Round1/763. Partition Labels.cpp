class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, pair<int, int>> letterPosition;
        for(int i = 0; i < S.size(); i++) {
        	char c = S[i];
        	if(letterPosition.count(c) == 0) {
        		letterPosition[c] = {i, i};
        	} else {
        		letterPosition[c].second = i;
        	}
        }
        vector<int> res;
        vector<pair<int, int>> intervals;
        for(auto it : letterPosition) {
        	intervals.push_back(it.second);
        }

        auto comp = [](pair<int, int> a, pair<int, int> b) {
		    return a.first < b.first;
		};
		sort(intervals.begin(), intervals.end(), comp);
		int end = -1, prev = 0;
		for(auto interval : intervals) {
			if(interval.first > end) {
				if(end >= 0) {
					res.push_back(end - prev);
				}
				prev = end;
			}

			end = max(end, interval.second);
		}
		res.push_back(end - prev);

        return res;
    }
};