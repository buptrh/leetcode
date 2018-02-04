class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        set<int> nodes;
        map<int, int> nodeTimes;
        map<int, vector<pair<int, int>>> edges;
        for(int i = 1; i <= N; i++) {
        	nodeTimes[i] = INT_MAX;
        }
        for(int i = 0; i < times.size(); i++) {
        	edges[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        nodeTimes[K] = 0;
        int count = N;
        int res = 0;
        while(count > 0) {
        	int index = -1;
	        for(int i = 1; i <= N; i++) {
	        	if(nodes.find(i) != nodes.end()) {
	        		continue;
	        	}
	        	if(index < 0 || nodeTimes[i] < nodeTimes[index]) {
	        		index = i;
	        	}
	        }
	        nodes.insert(index);
	        count --;
	        int dist = nodeTimes[index];
	        // cout<<"Find: " << index << "  " << dist<<endl;
	        for(pair<int, int> p : edges[index]) {
	        	if(nodes.find(p.first) != nodes.end()) {
	        		continue;
	        	}
	        	nodeTimes[p.first] = min(nodeTimes[p.first], dist + p.second);
	        }
	        res = max(res, dist);
        }
        if(res == INT_MAX) {
        	res = -1;
        }
        return res;
    }
};