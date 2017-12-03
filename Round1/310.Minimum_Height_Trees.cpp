class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	std::vector<int> vRet;
    	if(edges.size() == 0) {
    		for(int i = 0; i < n; i++ ) {
    			vRet.emplace_back(i);
    		}
    		return vRet;
    	}
    	std::vector<std::vector<int> > table (n);
        for(int i = 0; i < edges.size(); i++) {
        	table[edges[i].first].emplace_back(edges[i].second);
        	table[edges[i].second].emplace_back(edges[i].first);
        }
        for(int i = 0; i < n; i++) {
        	if(table[i].size() == 1) {
        		vRet.emplace_back(i);
        	}
        }

        while(n > 2) {
        	n -= vRet.size();
        	std::vector<int> vTemp;
        	for(int i = 0; i < vRet.size(); i++) {
        		int next = table[vRet[i]][0];
        		auto ite = find(table[next].begin(), table[next].end(), vRet[i]);
        		if(ite != table[next].end()) {
        			table[next].erase(ite);
        		}
        		if(table[next].size() == 1) {
        			vTemp.emplace_back(next);
        		}
        	}
        	vRet = vTemp;
        }
        return vRet;
    }
};