class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(res, path, 0, graph);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int> & path, int index, vector<vector<int>>& graph) {
    	if(index == graph.size() - 1 ) {
    		res.push_back(path);
    		return;
    	}
    	for(int i = 0; i < graph[index].size(); i++) {
    		path.push_back(graph[index][i]);
    		dfs(res, path, graph[index][i], graph);
    		path.pop_back();
    	}
    }
};