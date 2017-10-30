class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
    	auto comp = [](pair<string, string> a, pair<string, string> b) {
		    return a.second < b.second;
		};
        sort(tickets.begin(), tickets.end(), comp);
        vector<string> path;
        vector<bool> used(tickets.size(), false);
        dfs(tickets, path, used, "JFK", 0);
        return path;
    }

    bool dfs(vector<pair<string, string>>& tickets, vector<string>& path, vector<bool>& used, string from, int count) {
    	if(count == tickets.size()) {
    		path.push_back(from);
    		return true;
    	}
    	for(int i = 0; i < tickets.size(); i++) {
    		if(used[i] || tickets[i].first != from) {
    			continue;
    		}
    		used[i] = true;
    		path.push_back(from);
    		if(dfs(tickets, path, used, tickets[i].second, count+1)) {
    			return true;
    		}
    		path.pop_back();
    		used[i] = false;
    	}
    	return false;
    }


};