class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<int> output;
        vector<int> indegree(numCourses, 0);
        vector<set<int>> graph(numCourses, set<int>());
        for(pair<int, int> pre : prerequisites) {
        	graph[pre.second].insert(pre.first);
        }
        for(set<int> neighbors : graph) {
        	for(auto neighbor : neighbors) {
        		indegree[neighbor]++;
        	}
        }

        for(int i = 0; i < numCourses; i++) {
        	if(indegree[i] == 0) {
       			output.push(i);
        	}
        }
        while(output.size() != 0) {
        	int i = output.front();
        	output.pop();
        	for(auto neighbor : graph[i]) {
        		indegree[neighbor] --;
        		if(indegree[neighbor] == 0) {
        			output.push(neighbor);
        		}
        	}
        }
        for(int i = 0; i < numCourses; i++) {
        	if(indegree[i] > 0) {
        		return false;
        	}
        }
        return true;
    }
};