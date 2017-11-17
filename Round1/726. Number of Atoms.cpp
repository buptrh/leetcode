class Solution {
public:
    string countOfAtoms(string formula) {
        string ret = "";
        int start = 0;
		map<string, int> table = helper(formula, start);
		for(auto it : table){
			if(it.second == 0) {
				continue;
			}
			ret += it.first;
			if(it.second > 1) {
				ret += to_string(it.second);
			}
		}
        return ret;
    }

    map<string, int> helper(string & formula, int & start) {
    	map<string, int> table;
    	while(start < formula.size()) {
    		// cout<< "check" << start<<endl;
    		if(formula[start] <= 'Z' && formula[start] >= 'A') {
	    		string name = "";
	    		name += formula[start];
	    		start++;
	    		while((formula[start] <= 'z' && formula[start] >= 'a') || formula[start] == '0') {
	    			name += formula[start];
	    			start++;
	    		}
	    		int count = getCount(formula, start);
	    		table[name] += count;
	    	} else if(formula[start] == '(') {
	    		start++;
	    		map<string, int> subtable = helper(formula, start);
	    		int count = getCount(formula, start);
	    		combineTables(table, subtable, count);
	    	} else if(formula[start] == ')') {
	    		start++;
	    		break;
	    	} else {
	    		break;
	    	}
    	}
    	// outputTables(table);
    	return table;
    }

    int getCount(string & formula, int & start) {
    	// cout<<"count" << start ;
    	int count = 1;
		string c = "";
		while(formula[start] <= '9' && formula[start] >= '0') {
			c += formula[start];
			start++;
			if(start >= formula.size()) {
				break;
			}
		}
		if(c.size() > 0) {
			count = stoi(c);
		}
    	// cout<<". " << start<<endl;
		return count;
    }

    void combineTables(map<string, int> & source, map<string, int> & target, int multiply) {
		for(auto it : target) {
			source[it.first] += it.second * multiply;
		}
    }
    void outputTables(map<string, int> & target) {
    	cout<<"output:: " << endl;
		for(auto it : target) {
			cout<< it.first << "  " << it.second<<endl;
		}
		cout<<endl;
    }
};