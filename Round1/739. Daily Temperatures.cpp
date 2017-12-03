class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    	stack<pair<int, int>> sta;
    	vector<int> res(temperatures.size(), 0);
        for(int i = temperatures.size()-1; i >= 0; i--) {
        	while(sta.size() != 0 && temperatures[i] >= sta.top().first) {
        		sta.pop();
        	}
        	if(sta.size() > 0) {
        		res[i] = sta.top().second - i;
        	} else {
        		res[i] = 0;
        	}
        	sta.push(make_pair(temperatures[i], i));
        }
        return res;
    }
};