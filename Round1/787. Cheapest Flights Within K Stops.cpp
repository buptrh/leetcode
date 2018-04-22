class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    	if(src == dst) {
    		return 0;
    	}
        unordered_map<int, vector<pair<int, int>>> flightsMap;
        for(vector<int> flight : flights) {
        	flightsMap[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }

        int res = INT_MAX;
        queue<pair<int, int>> currents;
        currents.push(make_pair(src, 0));
        unordered_map<int, int> visited;
        for(int i = 0; i <= K; i++) {
        	
        	int size = currents.size();
        	for(int j = 0; j < size; j++) {
        		pair<int, int> p = currents.front();
        		currents.pop();
        		if(visited[p.first] != 0 && p.second > visited[p.first]) {
        			continue;
        		}
    			// cout<< p.first << "  " << p.second << endl;;
        		visited[p.first] = p.second;
        		vector<pair<int, int>> arrive = flightsMap[p.first];
        		for(pair<int, int> a : arrive) {
        			currents.push(make_pair(a.first, a.second + p.second));
        			if(a.first == dst) {
        				res = min(res, a.second + p.second);
        			}
        		}

        	}
        }
        if(res == INT_MAX) {
        	res = -1;
        }

        return res;
    }
};