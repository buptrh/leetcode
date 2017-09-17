class Solution {
public:
    string minWindow(string s, string t) {
    	map<int, int> table;
        for(int i = 0; i < t.size(); i++) {
        	table[t[i]] ++;
        }
        int count = t.size();

        string ret;
        int minCount = INT_MAX;
        set<int> pos;

        for(int i = 0; i < s.size(); i++) {
        	if(table.find(s[i]) != table.end()) {
        		if( table[s[i]] > 0) {
	        		table[s[i]]--;
	        		count--;
	        		pos.insert(i);
	        			// cout<<"find" << s[i] << "  " << i << "  " << *pos.begin()<<endl;
	        		while(i - *pos.begin() > minCount) {
		        		table[s[*pos.begin()]]++;
		        		count++;
		        		pos.erase(pos.begin());
	        		}
	        		if(count == 0) {
	        			// cout<<"fff" << minCount << "  " << i << "  " << *pos.begin()<<endl;
	        			if( minCount > i - *pos.begin()) {
		        			minCount = i - *pos.begin()+1;
		        			ret = s.substr(*pos.begin(), minCount);
		        		}
		        		table[s[*pos.begin()]]++;
		        		// cout<<"after" << table[s[pos.begin()]] << endl;
		        		count++;
		        		pos.erase(pos.begin());
	        		}
        		} else {
        			for(set<int>::iterator it = pos.begin(); it != pos.end(); it++) {
        				if(s[*it] == s[i]) {
        					// cout<<"remove" << s[*it] << "  " << *it << " to:" << i <<  endl;
        					pos.erase(*it);
        					break;
        				}
        			}
        			pos.insert(i);
        		}
        	}
        }

        return ret;

    }
};