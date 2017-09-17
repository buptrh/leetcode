class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }

    map<string, int> table;
    
    void insert(string key, int val) {
        table[key] = val;
    }
    
    int sum(string prefix) {
    	int ret = 0;
        for(auto it = table.begin(); it != table.end(); it++) {
        	string key = it->first;
        	int val = it->second;
        	if(key.substr(0, prefix.size()) == prefix) {
        		ret += val;
        	}
        }
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */