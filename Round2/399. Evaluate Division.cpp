class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, vector<pair<string, double>>> table;
        for(int i = 0; i < equations.size(); i++) {
        	table[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
        	table[equations[i].second].push_back(make_pair(equations[i].first, 1.0/values[i]));
        }

        vector<double> ret;

        for(pair<string, string> query : queries) {
	        map<string, bool> used;
	        double val = 1.0;
        	if(dfs(table, used, query.first, query.second, val )){
        		ret.push_back(val);
        	} else {
        		ret.push_back(-1.0);
        	}
        }

        return ret;
    }

    bool dfs(map<string, vector<pair<string, double>>> & table, map<string, bool> & used, string key, string target, double & val) {
    	vector<pair<string, double>> variables = table[key];
    	for(int i = 0; i < variables.size(); i++) {
    		pair<string, double> variable = variables[i];
    		if(used[variable.first]) {
    			continue;
    		}
    		used[variable.first] = true;
    		val *= variable.second;
    		if(variable.first == target) {
    			return true;
    		}
    		if(dfs(table, used, variable.first, target, val)) {
    			return true;
    		}
    		val /= variable.second;
    		used[variable.first] = false;
    	}
    	return false;
    }
};