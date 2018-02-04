class Solution {
public:
    bool canTransform(string start, string end) {
    	if(start.size() != end.size() ) {
    		return false;
    	}
    	// cout<< offset << endl;
    	int i = 0;
    	char c = 0;
        while(i < start.size()) {
        	c = 0;
        	int j = i;
        	while(j < start.size() && start[j] == 'X') {
        		j++;
        	}
        	if(j < start.size()) {
        		c = start[j];
        		int count = 0;
        		if(c == 'L') {
        			if(end[i] == 'R') {
        				return false;
        			}
        			while(i < start.size()) {
        				if(start[i] == 'R' || end[i] == 'R') {
        					break;
        				}
        				if(start[i] == 'L') {
        					count++;
        				}
        				if(end[i] == 'L') {
        					count--;
        				}
        				if(count > 0) {
        					return false;
        				}
        				i++;
        			}
        			if(count != 0) {
        				return false;
        			}
        		} else if(c == 'R') {
        			if(end[i] == 'L') {
        				return false;
        			}
        			while(i < start.size()) {
        				if(start[i] == 'L' || end[i] == 'L') {
        					break;
        				}
        				if(start[i] == 'R') {
        					count++;
        				}
        				if(end[i] == 'R') {
        					count--;
        				}
        				if(count < 0) {
        					return false;
        				}
        				i++;
        			}
        			if(count != 0) {
        				return false;
        			}
        		}
        	} else {
        		while(i < j) {
        			if(end[i] != 'X') {
        				return false;
        			}
        			i++;
        		}
        	}
        }
        return true;
    }
};