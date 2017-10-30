class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        map<int, vector<int>> table;
        for(pair<int, int> pre : prerequisites) {
        	table[pre.second].push_back(pre.first);
        	indegrees[pre.first]++;
        }

        queue<int> courses;
        for(int i = 0; i < indegrees.size(); i++) {
        	if(indegrees[i] == 0) {
        		courses.push(i);
        	}
        }

        vector<int> ret;
        while(courses.size() != 0) {
        	int i = courses.front();
        	courses.pop();
        	ret.push_back(i);
        	for(int j : table[i]) {
        		indegrees[j]--;
        		if(indegrees[j] == 0) {
        			courses.push(j);
        		}
        	}
        }
        if(ret.size() == numCourses) {
        	return ret;
        } else {
        	return vector<int>();
        }
    }
};