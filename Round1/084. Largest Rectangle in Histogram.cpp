class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	stack<pair<int, int>> sta;
    	int max_area = 0;
        for(int i = 0; i < heights.size(); i++) {
        	int preIndex = j;
        	while(sta.size() != 0 && sta.top().second > heights[i]) {
        		preIndex = sta.top().first;
        		max_area = max(max_area, sta.top().second * (i - sta.top().first));
        		sta.pop();
        	}
        	sta.push(pair<int, int>(preIndex, heights[i]));
        }

        while(sta.size() != 0) {
    		max_area = max(max_area, sta.top().second * ((int)heights.size() - sta.top().first));
    		sta.pop();
    	}
    	return max_area;
    }
};