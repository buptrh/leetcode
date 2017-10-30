class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> degrees(n, 0);
        map<int, vector<int>> table;
        for(auto edge : edges) {
        	table[edge.first].push_back(edge.second);
        	table[edge.second].push_back(edge.first);
        	degrees[edge.first]++;
        	degrees[edge.second]++;
        }
        queue<int> nodes;
        for(int i = 0; i < degrees.size(); i++) {
        	if(degrees[i] <= 1) {
        		nodes.push(i);
        	}
        }

        vector<int> ret;
        while(!nodes.empty()) {
        	bool right = false;
        	if(n == nodes.size()) {
        		right = true;
        	}
        	int size = nodes.size();

        	for(int i = 0; i < size; i++) {
        		int j = nodes.front();
        		nodes.pop();
        		if(right) {
        			ret.push_back(j);
        		}
        		for(int m : table[j]) {
        			if(degrees[m] > 0) {
        				degrees[m]--;
        				if(degrees[m] == 1) {
        					nodes.push(m);
        				}
        			}
        		}
        		n--;
        	}
        }
        return ret;
    }
};