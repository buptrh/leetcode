class Solution {
public:

    bool  canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		map<int, vector<int> > courseMap;
        vector<int> indegres (numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++) {
        	if(courseMap.find(prerequisites[i].second) == courseMap.end() ) {
        		courseMap[prerequisites[i].second] = std::vector<int>();
        	}

        	courseMap[prerequisites[i].second].emplace_back(prerequisites[i].first);
       		indegres[prerequisites[i].first]++;
        }

        queue<int> outputQueue;
        for(int i = 0; i < numCourses; i++) {
        	if(indegres[i] == 0) {
        		outputQueue.emplace(i);
        	}
        }
        cout<<outputQueue.size()<<endl;

        while(outputQueue.size() > 0) {
        	int output = outputQueue.front();
        	outputQueue.pop();

        	vector<int> courses = courseMap[output];
        	for(int i = 0; i < courses.size(); i++) {
        		indegres[courses[i]] --;
        		if(indegres[courses[i]] == 0) {
        			outputQueue.emplace(courses[i]);
        		}
        	}
        }

        for(int i = 0; i < numCourses; i++) {
        	if(indegres[i] > 0) {
        		return false ;
        	} 
        }

        return true;

    }

};