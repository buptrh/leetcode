class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        std::vector<string> ret;
        auto comp = [](pair<string, string> a, pair<string, string> b) {
		    return a.second < b.second;
		};
		sort(tickets.begin(), tickets.end(), comp);
        string current = "JFK";
        ret.push_back(current);
        set<int> used;
        helper(tickets, used, current, ret);
        return ret;
    }

   	void helper(vector<pair<string, string>> & tickets, set<int> & used, string current, vector<string> & ret) {
   		if(tickets.size() == ret.size()-1) {
   			return;
   		}
   		for(int i = 0; i < tickets.size(); i++) {
   			if(used.find(i) == used.end() && tickets[i].first == current) {
   				// cout << "find: " << tickets[i].first << endl;
   				used.insert(i);
   				string newcurrent = tickets[i].second;
   				ret.push_back(newcurrent);
   				helper(tickets, used, newcurrent, ret);
   				if(tickets.size() == ret.size()-1) {
   					break;
   				}
   				ret.pop_back();
   				used.erase(i);
   			}
   		}

   	}

};