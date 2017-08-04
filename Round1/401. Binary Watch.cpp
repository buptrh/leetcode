class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        
    	vector<string> ret;
        helper(ret, num, 0, 0, 0);
        return ret;
    }
    void helper(vector<string> & ret, int num, int from, int hoursOffset, int minuteOffset) {
    	if(hoursOffset >= 12 || minuteOffset >= 60 || from >= 10 || num > 10 - from) {
    		return;
    	}
		// cout<< "in: " << from << "  " << num << "  " << hoursOffset << "  " << minuteOffset << endl;

		if(num == 0) {
			string time;
    		time += to_string(hoursOffset) + ":";
    		if(minuteOffset < 10) {
    			time += "0";
    		}
    		time += to_string(minuteOffset);
    		ret.emplace_back(time);
		} else if(num == 10 - from) {
    		int hours = 0, mins = 0;
    		for(int i = from; i < 4; i++) {
    			hours += 1 << i;
    		}
    		for(int i = max(4, from); i <= 9; i++) {
    			mins += 1 << (i - 4);
    		}
    		// cout<< "out: " << from << "  " << num << "  " << hours << "  " << mins << endl;
    		hours += hoursOffset;
    		mins += minuteOffset;
    		if(hours >= 12 || mins >= 60 ) {
    			return;
    		}
    		string time;
    		time += to_string(hours) + ":";
    		if(mins < 10) {
    			time += "0";
    		}
    		time += to_string(mins);
    		ret.emplace_back(time);
    	} else {
	    	helper(ret, num, from+1, hoursOffset, minuteOffset);
	    	if(num > 0) {
    			int hours = hoursOffset, mins = minuteOffset;
	    		if(from < 4) {
	    			hours += 1 << from;
	    		} else {
	    			mins += 1 << (from - 4);
	    		}
	    		// cout<<"recu: " << hoursOffset << "  " << hours << "  "  << minuteOffset << "  " << mins <<  "  "<< from << endl;
	    		helper(ret, num-1, from+1, hours, mins);
	    	}
    	}


    	return;
    }
};