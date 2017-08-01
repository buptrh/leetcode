class Solution {
public:
    string predictPartyVictory(string senate) {
    	int retAlive = 0, retDeadR = 0, retDeadD = 0;
    	bool lastR = false, lastD = false;
    	set<int> remove;
    	while(true) {
        	lastR = false;
        	lastD = false;
	        for(int i = 0; i < senate.size(); i++) {
	        	if(remove.find(i) != remove.end()) {
	        		continue;
	        	}

	        	if(senate[i] == 'R') {
	        		if(retDeadR > 0) {
	        			retDeadR--;
	        			remove.insert(i);
	        		} else {
	        			retDeadD ++;
	        			lastD = true;
	        		}
	        	} else {
	        		if(retDeadD > 0) {
	        			retDeadD--;
	        			remove.insert(i);
	        		} else {
	        			retDeadR ++;
	        			lastR = true;
	        		}
	        	}
	        }
	        if(lastD == false) {
	        	return "Dire";
	        }
	        if(lastR == false) {
	        	return "Radiant";
	        }
    	}
    	return "Radiant";
     }
};