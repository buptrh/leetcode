class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> table;
        for(char c : t) {
        	table[c]++;
        }
        int count = t.size();
        int start = 0, minL = INT_MAX, head = -1;
        for(int i = 0; i < s.size(); i++) {
        	if(table.find(s[i]) == table.end()) {
        		continue;
        	}
        	if(table[s[i]] > 0) {
        		count--;
        	}
    		table[s[i]]--;
        	while(count == 0) {
        		if(i - start + 1 < minL) {
        			minL = i - start + 1;
        			head = start;
        		}
	        	if(table.find(s[start]) == table.end()) {
	        		start++;
	        		continue;
	        	}
	        	if(table[s[start]] >= 0) {
	        		count++;
	        	}
	        	table[s[start]] ++;
	        	start++;
        	}
        }
        if(head >= 0) {
        	return s.substr(head, minL);
        } else {
        	return "";
        }
    }
};