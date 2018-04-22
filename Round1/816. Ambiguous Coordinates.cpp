class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ret;
        unordered_map<string, vector<string>> cache;
        string s = S.substr(1, S.size()-2);
        dfs(s, ret, cache);
        return ret;
    }

    void dfs(string s, vector<string> & ret, unordered_map<string, vector<string>>& cache) {
    	string prev;
    	for(int i = 0; i < (int)s.size()-1; i++) {
    		prev.push_back(s[i]);
    		string next = s.substr(i+1);
    		legalSep(prev, cache);
    		legalSep(next, cache);
    		// cout<< "!! " << s << ": " << prev << " , " << next <<endl;
    		for(string s1 : cache[prev]) {
    			for(string s2 : cache[next]) {
    				ret.push_back("(" + s1 + ", " + s2 + ")");
    			}
    		}
    	}
    }

    void legalSep(string s, unordered_map<string, vector<string>>& cache) {
    	if(s.size() <= 0) {
    		return;
    	}
    	if(cache.find(s) != cache.end()) {
    		return;
    	}
    	vector<string> ret;
    	string temp;
    	if(legalInt(s)) {
    		ret.push_back(s);
    	}
    	for(int i = 0; i < s.size(); i++) {
    		temp.push_back(s[i]);
    		if(legalInt(temp) && legalPoint(s.substr(i+1))) {
    			ret.push_back(temp + "." + s.substr(i+1));
    		}
    	}
    	cache[s] = ret;

    }

    bool legalInt(string s) {
    	bool res;
    	if(s.size() <= 0 || (s[0] == '0' && s.size() > 1)) {
    		 res = false;;
    	} else {

    		res = true;
    	}
    	// cout<<"legalInt " << s <<". " <<res <<endl;
    	return res;
    }
    bool legalPoint(string s) {
    	if(s.size() <= 0 || s[s.size()-1] == '0') {
    		return false;
    	}
    	return true;
    }
};