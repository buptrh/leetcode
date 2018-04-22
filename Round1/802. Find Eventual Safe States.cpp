class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    	vector<int> res;
    	unordered_set<int> resset;
		bool flag = false;
    	while(true) {
    		flag = false;
	        for(int i = 0; i < graph.size(); i++) {
	        	if(resset.count(i) > 0) {
	        		continue;
	        	}
	        	if(graph[i].size() == 0) {
	        		resset.insert(i);
	        		res.push_back(i);
	        		flag = true;
	        		continue;
	        	}
	        	bool need = true;
	        	for(int j = 0; j < graph[i].size(); j++) {
	        		if(resset.count(graph[i][j]) == 0) {
	        			need = false;
	        			break;
	        		}
	        	}
	        	if(need) {
	        		resset.insert(i);
	        		res.push_back(i);
	        		flag = true;
    				// cout<< "mmm " << flag << endl;
	        	}
	        }
    		// cout<< "ttt " << flag << endl;
	        if(!flag) {
	        	break;
	        }
    	}
    	sort(res.begin(), res.end());
    	return res;
    }
};