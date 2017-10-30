class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        map<int, int> indegree, outdegree;
        map<int, vector<int>> child, parent;
        int N = 0;
        for(vector<int> edge : edges) {
        	N = max(N, edge[0]);
        	N = max(N, edge[1]);
        	outdegree[edge[0]]++;
        	indegree[edge[1]]++;
        	child[edge[0]].push_back(edge[1]);
        	parent[edge[1]].push_back(edge[0]);
        }

        vector<int> errorOneParent;
        int errorNoParent = 0;
        for(int i = 1; i <= N; i++) {
        	if(parent[i].size() > 1) {
        		errorOneParent.push_back(i);
        	}

        	if(parent[i].size() == 0) {
        		errorNoParent++;
        	}
        }

        vector<int> ret;
        for(int i = edges.size()-1; i >= 0; i--) {
        	if(errorNoParent == 1) {
        		if(indegree[edges[i][1]] > 1 && !(outdegree[edges[i][0]] == 1 && indegree[edges[i][0]] == 0)) {
        			
        			return edges[i];
        		}
        	} else {
        		if(indegree[edges[i][1]] == 1 && outdegree[edges[i][1]] > 0) {
        			return edges[i];
        		}
        	}
        }
        return ret;
    }


};